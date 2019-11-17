/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:32:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/17 07:21:41 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdio.h>

s_light			*new_default_light(int type, float intensity, int color)
{
	s_light		*light;

	if (!(light = malloc(sizeof(s_light))))
		return (NULL);
	light->type = type;
	light->intensity = intensity;
	light->vector = new_vector(0, 0, 0);
	light->color = color;
	return (light);
}

s_light			*new_point_light(s_vector *pos, float intensity, int color)
{
	s_light		*light;

	if (!(light = malloc(sizeof(s_light))))
		return (NULL);
	light->type = TYPE_POINT;
	light->intensity = intensity;
	light->vector = pos;
	light->color = color;
	return (light);
}
