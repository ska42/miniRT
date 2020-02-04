/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 17:08:47 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_window(t_mlx *my_mlx)
{
	mlx_clear_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
	mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr,
my_mlx->mlx_img, 0, 0);
	mlx_hook(my_mlx->win_ptr, 2, 1L << 0, handle_key, my_mlx);
	mlx_hook(my_mlx->win_ptr, 17, 1L << 17, exit_program, 0);
	mlx_loop(my_mlx->mlx_ptr);
}

t_mlx	*init_my_mlx(t_scene *scene)
{
	t_mlx		*my_mlx;

	if (!(my_mlx = malloc(sizeof(t_mlx))))
		print_error_and_exit(-7);
	my_mlx->mlx_ptr = mlx_init();
	my_mlx->scene = scene;
	my_mlx->mlx_img = mlx_new_image(my_mlx->mlx_ptr,
my_mlx->scene->viewport->width, my_mlx->scene->viewport->height);
	my_mlx->data = mlx_get_data_addr(my_mlx->mlx_img,
&my_mlx->bpp, &my_mlx->size_line, &my_mlx->endian);
	my_mlx->win_ptr = mlx_new_window(my_mlx->mlx_ptr,
my_mlx->scene->viewport->width, my_mlx->scene->viewport->height, "miniRT");
	return (my_mlx);
}

int		main(int argc, char *argv[])
{
	t_mlx			*my_mlx;
	int				fd;
	t_scene			*scene;
	int				i;

	if (argc < 2 || argc > 3)
		print_error_and_exit(-9);
	i = open_and_check_error(argv[1], &fd);
	if (!(scene = parsing(fd)))
		print_error_and_exit(-4);
	close(fd);
	my_mlx = init_my_mlx(scene);
	create_image(my_mlx);
	if (argc == 2)
		start_window(my_mlx);
	else if (argc == 3 && !(ft_strcmp(argv[2], "-save")))
		export_bmp(create_bmp_filename(argv[1], i), my_mlx);
	else
		print_error_and_exit(-10);
}
