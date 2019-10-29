/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:32:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:30:06 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

s_light			*new_default_light(int type, float intensity)
{
	s_light		*light;

	light = malloc(sizeof(s_light));
	light->type = type;
	light->intensity = intensity;
	light->vector = new_vector(0, 0, 0);
	return (light);
}
