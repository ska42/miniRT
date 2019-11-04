/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:51:43 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 08:34:14 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vector.h"

s_camera		*new_camera(s_vector *pos, s_vector *rota)
{
	s_camera	*camera;

	camera = malloc(sizeof(s_camera));
	camera->rotation = rota;
	camera->origin = pos;
	return (camera);
}
