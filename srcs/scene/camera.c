/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:51:43 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/24 02:15:57 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "camera.h"
#include "vector.h"

t_camera		*new_camera(t_vector *pos, t_vector *rota, int fov)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		print_error_and_exit(-7);
	camera->rotation = rota;
	camera->origin = pos;
	camera->fov = fov;
	return (camera);
}

t_camera		*cpy_camera(t_camera *cam)
{
	t_vector	*pos;
	t_vector	*rota;

	pos = new_vector(cam->origin->x, cam->origin->y, cam->origin->z);
	rota = new_vector(cam->rotation->x, cam->rotation->y, cam->rotation->z);
	return (new_camera(pos, rota, cam->fov));
}
