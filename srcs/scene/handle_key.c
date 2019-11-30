/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 23:01:49 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 23:05:11 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		exit_program(void)
{
	exit(0);
	return (0);
}

int		handle_key(int keycode, s_mlx *my_mlx)
{
	s_vector *origin;
	s_vector *rotation;

	origin = ((s_camera *)my_mlx->scene->cameras->object)->origin;
	rotation = ((s_camera *)my_mlx->scene->cameras->object)->rotation;
	if (keycode == 53)
		return (exit_program());
	if (!(keycode >= 0 && keycode <= 3) && !(keycode >= 12 && keycode <= 15) &&
		!(keycode >= 123 && keycode <= 126) && keycode != 83 && keycode != 84)
		return (0);
	origin->x -= 0.5 * ((keycode == KEYCODE_A) ? 1 : 0);
	origin->x += 0.5 * ((keycode == KEYCODE_D) ? 1 : 0);
	origin->z -= 0.5 * ((keycode == KEYCODE_S) ? 1 : 0);
	origin->z += 0.5 * ((keycode == KEYCODE_W) ? 1 : 0);
	origin->y -= 0.5 * ((keycode == KEYCODE_F) ? 1 : 0);
	origin->y += 0.5 * ((keycode == KEYCODE_R) ? 1 : 0);
	rotation->y -= 0.1 * ((keycode == KEYCODE_LEFT) ? 1 : 0);
	rotation->y += 0.1 * ((keycode == KEYCODE_RIGHT) ? 1 : 0);
	rotation->x -= 0.1 * ((keycode == KEYCODE_DOWN) ? 1 : 0);
	rotation->x += 0.1 * ((keycode == KEYCODE_UP) ? 1 : 0);
	rotation->z -= 0.1 * ((keycode == KEYCODE_1) ? 1 : 0);
	rotation->z += 0.1 * ((keycode == KEYCODE_2) ? 1 : 0);
	if (keycode == KEYCODE_Q)
		my_mlx->scene->cameras = (s_lstobjects *)my_mlx->scene->cameras->prev;
	if (keycode == KEYCODE_E)
		my_mlx->scene->cameras = (s_lstobjects *)my_mlx->scene->cameras->next;
	create_image(my_mlx);
	mlx_clear_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
	mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr,
my_mlx->mlx_img, 0, 0);
	return (0);
}
