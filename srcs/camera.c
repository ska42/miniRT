/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:51:43 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 04:24:00 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vector.h"

s_camera		*new_camera(s_vector *pos, s_vector *rota_x, s_vector *rota_y, s_vector *rota_z)
{
	s_camera	*camera;

	camera = malloc(sizeof(s_camera));
	camera->rotation = new_rotation(rota_x, rota_y, rota_z);
	camera->origin = pos;
	return (camera);
}
