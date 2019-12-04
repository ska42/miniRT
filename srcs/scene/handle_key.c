/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 23:01:49 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:50:03 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		exit_program(void)
{
	exit(0);
	return (0);
}

/*
** Move/Switch camera and quit program with ESC
*/

int		handle_key(int k, t_mlx *my_mlx)
{
	t_vector *o;
	t_vector *r;

	o = ((t_camera *)my_mlx->scene->cameras->object)->origin;
	r = ((t_camera *)my_mlx->scene->cameras->object)->rotation;
	if (k == 53)
		return (exit_program());
	if (!(k >= 0 && k <= 3) && !(k >= 12 && k <= 15) &&
		!(k >= 123 && k <= 126) && k != 83 && k != 84)
		return (0);
	o->x += ((k == KEYCODE_A) ? -0.5 : 0) + ((k == KEYCODE_D) ? 0.5 : 0);
	o->y += ((k == KEYCODE_S) ? -0.5 : 0) + ((k == KEYCODE_W) ? 0.5 : 0);
	o->z += ((k == KEYCODE_F) ? -0.5 : 0) + ((k == KEYCODE_R) ? 0.5 : 0);
	r->x += ((k == KEYCODE_DOWN) ? -0.1 : 0) + ((k == KEYCODE_UP) ? 0.1 : 0);
	r->y += ((k == KEYCODE_LEFT) ? -0.1 : 0) + ((k == KEYCODE_RIGHT) ? 0.1 : 0);
	r->z += ((k == KEYCODE_1) ? -0.1 : 0) + ((k == KEYCODE_2) ? 0.1 : 0);
	if (k == KEYCODE_Q)
		my_mlx->scene->cameras = (t_lstobjects *)my_mlx->scene->cameras->prev;
	if (k == KEYCODE_E)
		my_mlx->scene->cameras = (t_lstobjects *)my_mlx->scene->cameras->next;
	create_image(my_mlx);
	mlx_clear_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
	mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr,
my_mlx->mlx_img, 0, 0);
	return (0);
}
