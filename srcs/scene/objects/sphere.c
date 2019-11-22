/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:11:17 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/21 23:23:16 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

s_sphere		*new_sphere(float radius, int color, float shiny,
s_vector *center)
{
	s_sphere	*sphere;

	sphere = malloc(sizeof(s_sphere));
	sphere->radius = radius;
	sphere->color = color;
	sphere->center = center;
	sphere->shiny = shiny;
	sphere->reflective = 0.5;
	return (sphere);
}

s_sphere		*new_default_sphere(float radius, int color)
{
	return (new_sphere(radius, color, -1, new_vector(0, 0, 0)));
}

void			set_reflective(s_sphere *sphere, float reflective)
{
	sphere->reflective = reflective;
}

void 			set_shiny(s_sphere *sphere, float shiny)
{
	sphere->shiny = shiny;
}
