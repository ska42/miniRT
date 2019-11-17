/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:01:25 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/17 02:38:15 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_cylinder	*new_cylinder(s_vector *vectors[2], float diameter, float height, int color)
{
	s_cylinder	*new;
	s_vector	*temp;
	float		total;
	//float		test;
	//s_vector	*direction;
	//s_vector	*vector[2];

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
	//test = distance_points(*new->point1, *new->point2);
	//printf("test : %f\n", test);
	//temp = multiply_vectors(tt, *object->orientation);
	//point_tmp = add_vectors(*point, *temp);
	//vector[0] = new_vector(0, 0, 0);
	//vector[1] = new_vector(0, 0, 0);
	//new->point1 = add_vectors(*vector[0], *new->center);
	//new->point2 = add_vectors(*vector[1], *new->center);
	//rot(new->point1, new->orientation);
	//rot(new->point2, new->orientation);
	/**
	vector[0] = new->center;
	rot(vector[0], new->orientation);
	new->point1 = add_vectors(*vector[0], *temp);
	//free(temp);
	vector[1] = new->center;
	rot(vector[1], new->orientation);
	//free(temp);
	new->point2 = add_vectors(*vector[1], *tem);
	**/
	//printf("point1 : %f %f %f\n", new->point1->x, new->point1->y, new->point1->z);
	//printf("point2 : %f %f %f\n", new->point2->x, new->point2->y, new->point2->z);
	new->diameter = diameter;
	new->height = height;
	new->color = color;
	new->shiny = -1;
	new->reflective = -1;
	return (new);
}
