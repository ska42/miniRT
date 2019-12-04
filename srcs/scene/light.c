/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:32:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/01 00:21:15 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "light.h"

t_light			*new_default_light(int type, float intensity, t_vector *color)
{
	t_light		*light;

	if (!(light = malloc(sizeof(t_light))))
		print_error_and_exit(-7);
	light->type = type;
	light->intensity = intensity;
	light->vector = new_vector(0, 0, 0);
	light->color = color;
	return (light);
}

t_light			*new_point_light(t_vector *pos, float intensity,
t_vector *color)
{
	t_light		*light;

	if (!(light = malloc(sizeof(t_light))))
		print_error_and_exit(-7);
	light->type = TYPE_POINT;
	light->intensity = intensity;
	light->vector = pos;
	light->color = color;
	return (light);
}
