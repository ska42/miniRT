/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:11:17 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:30:20 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

s_sphere		*new_sphere(float radius, int color, s_vector *center)
{
	s_sphere	*sphere;

	sphere = malloc(sizeof(s_sphere));
	sphere->radius = radius;
	sphere->color = color;
	sphere->center = center;
	return (sphere);
}

s_sphere		*new_default_sphere(float radius, int color)
{
	return (new_sphere(radius, color, new_vector(0, 0, 0)));
}
