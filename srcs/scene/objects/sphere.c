/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:11:17 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/23 22:45:50 by lmartin          ###   ########.fr       */
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
	sphere->calcul_c = 0;
	sphere->difference = NULL;
	sphere->prev_origin = NULL;
	return (sphere);
}

void			free_sphere(s_sphere *sphere)
{
	free(sphere->center);
	if (sphere->difference)
		free(sphere->difference);
	if (sphere->prev_origin)
		free(sphere->prev_origin);
	free(sphere);

}

s_sphere		*cpy_sphere(s_sphere *sphere)
{
	s_sphere	*new;

	new = malloc(sizeof(s_sphere));
	new->center = cpy_vector(sphere->center);
	new->radius = sphere->radius;
	new->color = sphere->color;
	new->shiny = sphere->shiny;
	new->calcul_c = 0;
	new->difference = NULL;
	new->prev_origin = NULL;
	return (new);
}
