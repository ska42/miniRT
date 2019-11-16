/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:51:43 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 05:53:01 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vector.h"

s_camera		*new_camera(s_vector *pos, s_vector *rota, int fov)
{
	s_camera	*camera;

	if (!(camera = malloc(sizeof(s_camera))))
		return (NULL);
	camera->rotation = rota;
	camera->origin = pos;
	camera->fov = fov;
	return (camera);
}
