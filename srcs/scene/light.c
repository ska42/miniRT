/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:32:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/24 02:15:45 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "light.h"

s_light			*new_default_light(int type, float intensity, s_vector *color)
{
	s_light		*light;

	if (!(light = malloc(sizeof(s_light))))
		print_error_and_exit(-7);
	light->type = type;
	light->intensity = intensity;
	light->vector = new_vector(0, 0, 0);
	light->color = color;
	return (light);
}

s_light			*new_point_light(s_vector *pos, float intensity, s_vector *color)
{
	s_light		*light;

	if (!(light = malloc(sizeof(s_light))))
		print_error_and_exit(-7);
	light->type = TYPE_POINT;
	light->intensity = intensity;
	light->vector = pos;
	light->color = color;
	return (light);
}
