/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 23:03:40 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		main(int argc, char *argv[])
{
	s_mlx			*my_mlx;
	int				fd;
	s_scene			*scene;
	int				i;

	(void)argc;
	if (!(my_mlx = malloc(sizeof(s_mlx))))
		print_error_and_exit(-7);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		print_error_and_exit(-1);
	i = 0;
	while (argv[1][i] != '.' && argv[1][i])
		i++;
	if (!argv[1][i])
		print_error_and_exit(-2);
	if (i < 3 || ft_strcmp(&argv[1][i], ".rt"))
		print_error_and_exit(-3);
	if (!(scene = parsing(fd)))
		print_error_and_exit(-4);
	close(fd);
	if (!scene->viewport)
		print_error_and_exit(-5);
	if (scene->viewport->height <= 0 || scene->viewport->width <= 0)
		print_error_and_exit(-6);
	if (scene->viewport->width > LIMIT_RES_X)
		scene->viewport->width = LIMIT_RES_X;
	if (scene->viewport->height > LIMIT_RES_Y)
		scene->viewport->height = LIMIT_RES_Y;
	if (scene->viewport->height < scene->viewport->width)
		scene->viewplane = new_canvas(scene->viewport->width/scene->viewport->height, 1, 1);
	else
		scene->viewplane = new_canvas(1, scene->viewport->height/scene->viewport->width, 1);
	my_mlx->mlx_ptr = mlx_init();
	my_mlx->scene = scene;
	my_mlx->mlx_img = mlx_new_image(my_mlx->mlx_ptr, my_mlx->scene->viewport->width, my_mlx->scene->viewport->height);
	my_mlx->data = mlx_get_data_addr(my_mlx->mlx_img, &my_mlx->bpp, &my_mlx->size_line, &my_mlx->endian);
	my_mlx->win_ptr = mlx_new_window(my_mlx->mlx_ptr, my_mlx->scene->viewport->width, my_mlx->scene->viewport->height, "miniRT");
	create_image(my_mlx);
	if (argc == 2)
	{
		mlx_clear_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
		mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr, my_mlx->mlx_img, 0, 0);
		mlx_hook(my_mlx->win_ptr, 2, 1L << 0, handle_key, my_mlx);
		mlx_hook(my_mlx->win_ptr, 17, 1L << 17, exit_program, 0);
		mlx_loop(my_mlx->mlx_ptr);
	}
	else if (argc == 3 && !(ft_strcmp(argv[2], "-save")))
	{
		// TO BMP
		int				n;
		char			*filename;

		if (!(filename = malloc(sizeof(char) * (i + 5))))
			print_error_and_exit(-7);
		n = -1;
		while (++n <= i)
			*(filename + n) = *(argv[1] + n);
		*(unsigned int *)(filename + n) = *(const unsigned int *)(unsigned long)"bmp\0";
		export_bmp(filename, my_mlx);
		exit(1);
	}
}
