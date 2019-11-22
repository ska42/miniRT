/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:01:25 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 04:50:11 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_cylinder	*new_cylinder(s_vector *vectors[2], float diameter, float height, int color)
{
	s_cylinder	*new;
	s_vector	*temp;
	float		total;

	new = malloc(sizeof(s_cylinder));
	new->center = vectors[0];
	new->orientation = vectors[1];


	total = fabs(new->orientation->x) + fabs(new->orientation->y) + fabs(new->orientation->z);
	temp = new_vector(height/2 * (new->orientation->x / total), height/2 * (new->orientation->y / total), height/2 * (new->orientation->z / total));
	new->point1 = add_vectors(*new->center, *temp);
	free(temp);
	temp = new_vector(-height/2 * (new->orientation->x / total), -height/2 * (new->orientation->y / total), -height/2 * (new->orientation->z / total));
	new->point2 = add_vectors(*new->center, *temp);
	free(temp);
	new->diameter = diameter;
	new->height = height;
	new->color = color;
	new->shiny = -1;
	new->reflective = -1;
	return (new);
}

void		free_cylinder(s_cylinder *cylinder)
{
	free(cylinder->center);
	free(cylinder->orientation);
	free(cylinder->point1);
	free(cylinder->point2);
	free(cylinder);
}

s_cylinder	*cpy_cylinder(s_cylinder *cylinder)
{
	s_cylinder *new;

	new = malloc(sizeof(s_cylinder));
	new->center = cpy_vector(cylinder->center);
	new->orientation = cpy_vector(cylinder->orientation);
	new->point1 = cpy_vector(cylinder->point1);
	new->point2 = cpy_vector(cylinder->point2);
	new->diameter = cylinder->diameter;
	new->height = cylinder->height;
	new->color = cylinder->color;
	new->shiny = cylinder->shiny;
	new->reflective = cylinder->reflective;
	return (new);
}
