/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:11:17 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/01 00:28:29 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "sphere.h"

t_sphere		*new_sphere(float radius, t_vector *color, float shiny,
t_vector *center)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		print_error_and_exit(-7);
	sphere->radius = radius;
	sphere->color = color;
	sphere->center = center;
	sphere->shiny = shiny;
	sphere->calcul_c = 0;
	sphere->difference = NULL;
	sphere->prev_origin = NULL;
	return (sphere);
}

void			free_sphere(t_sphere *sphere)
{
	free(sphere->center);
	free(sphere->color);
	if (sphere->difference)
		free(sphere->difference);
	if (sphere->prev_origin)
		free(sphere->prev_origin);
	free(sphere);
}

t_sphere		*cpy_sphere(t_sphere *sphere)
{
	t_sphere	*new;

	if (!(new = malloc(sizeof(t_sphere))))
		print_error_and_exit(-7);
	new->center = cpy_vector(sphere->center);
	new->color = cpy_vector(sphere->color);
	new->radius = sphere->radius;
	new->shiny = sphere->shiny;
	new->calcul_c = 0;
	new->difference = NULL;
	new->prev_origin = NULL;
	return (new);
}
