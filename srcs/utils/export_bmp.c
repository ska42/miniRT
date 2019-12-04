/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:38:49 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/01 01:05:15 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
** Fill the bmp file with my_mlx->data previously made
** Note : The file is filled by line, from the last to the first
*/

void	fill_bmp(char **data, t_mlx *my_mlx)
{
	int i;
	int j;
	int x;
	int y;

	i = HEADER_SIZE;
	y = my_mlx->scene->viewport->height;
	while (y--)
	{
		x = -1;
		while (++x < my_mlx->scene->viewport->width)
		{
			j = (x * (my_mlx->bpp / 8)) + (y * my_mlx->size_line);
			*(*data + i++) = *(my_mlx->data + j++);
			*(*data + i++) = *(my_mlx->data + j++);
			*(*data + i++) = *(my_mlx->data + j);
		}
	}
}

/*
** Initialize the header of bmp (char *data)
**
** HEADER
** Position | Hex	| Description
** 00		| 00	| TYPE OF BMP FILE
** 02		| 02	| TOTAL SIZE OF FILE
** 06-08	| 06-08	| RESERVED TO SIGN
** 10		| 0A	| HEADER SIZE
** =============================================================================
** HEADER INFOS
** Position | Hex	| Description
** 14		| 0E	| HEADER INFOS SIZE
** 18		| 12	| WIDTH OF IMG (PX)
** 22		| 16	| HEIGHT OF IMG (PX)
** 26		| 1A	| NUMBER OF PLANS
** 28		| 1C	| BITS PER PIXELS (1 - 4 - 8 - 24)
** 30		| 1E	| COMPRESSION TYPE
** 34		| 22	| SIZE OF IMG
** 38		| 26	| RES X PX PER METER
** 42		| 2A	| RES Y PX PER METER
** 46		| 2E	| NB OF USED COLOR (0 = MAX)
** 50		| 32	| NB OF INDEX OF COLOR (0 = ALL)
*/

void	header_bmp(char **data, t_mlx *my_mlx)
{
	unsigned int size;

	size = my_mlx->scene->viewport->height * my_mlx->scene->viewport->width * 3;
	*(unsigned short *)*data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*data + 2) = (size + HEADER_SIZE);
	*(unsigned int *)(*data + 6) = 0u;
	*(unsigned char *)(*data + 10) = HEADER_SIZE;
	*(unsigned int *)(*data + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(*data + 18) = my_mlx->scene->viewport->width;
	*(unsigned int *)(*data + 22) = my_mlx->scene->viewport->height;
	*(unsigned short *)(*data + 26) = 1;
	*(unsigned short *)(*data + 28) = 24;
	*(unsigned int *)(*data + 30) = 0;
	*(unsigned int *)(*data + 34) = (unsigned int)size;
	*(unsigned int *)(*data + 38) = 3780;
	*(unsigned int *)(*data + 42) = 3780;
	*(int *)(*data + 46) = 0;
	*(int *)(*data + 50) = 0;
}

/*
** Create bmp (char *data), put header and fill it, then put result into
** filename (*.bmp).
*/

void	export_bmp(char *filename, t_mlx *my_mlx)
{
	int				fd;
	unsigned int	size;
	unsigned int	i;
	char			*data;

	size = my_mlx->scene->viewport->height * my_mlx->scene->viewport->width * 3;
	if (!(data = malloc((size + HEADER_SIZE))))
		print_error_and_exit(-7);
	i = 0;
	while (i < size + HEADER_SIZE)
		data[i++] = 0;
	header_bmp(&data, my_mlx);
	fill_bmp(&data, my_mlx);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644)) <= 0)
		print_error_and_exit(-8);
	write(fd, data, (size + HEADER_SIZE));
	close(fd);
}

char	*create_bmp_filename(char *file, int i)
{
	char		*filename;
	int			n;

	if (!(filename = malloc(sizeof(char) * (i + 5))))
		print_error_and_exit(-7);
	n = -1;
	while (++n <= i)
		*(filename + n) = *(file + n);
	*(unsigned int *)(filename + n) =
	*(const unsigned int *)(unsigned long)"bmp\0";
	return (filename);
}
