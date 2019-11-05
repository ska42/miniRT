/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:17:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/05 09:10:35 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float		intersect_sphere(s_vector origin,
s_vector direction, s_sphere *object)
{
	s_vector	*difference;
	float		discriminant;
	float		k[3];
	float		t[2];

	difference = new_vector(origin.x - object->center->x,
origin.y - object->center->y, origin.z - object->center->z);
	k[0] = product_vectors(direction, direction);
	k[1] = 2 * product_vectors(*difference, direction);
	k[2] = product_vectors(*difference, *difference) -
(object->radius * object->radius);
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
		return (0);
	t[0] = (- k[1] + sqrt(discriminant)) / (2 * k[0]);
	t[1] = (- k[1] - sqrt(discriminant)) / (2 * k[0]);
	free(difference);
	if (t[0] < t[1])
		return (t[0]);
	return (t[1]);
}

float		intersect_plan(s_vector origin, s_vector direction, s_plan *object)
{
	float denom;
	float k[2];
	float t;

	t = 0;
	denom = -(product_vectors(*object->normal, *object->point));
	k[0] = product_vectors(origin, *object->normal) + denom;
	k[1] = product_vectors(direction, *object->normal);
	t = - (k[0] / k[1]);
	return ((t < 0) ? 0 : t);
}

float		intersect_square(s_vector origin, s_vector direction, s_square *object)
{
	s_vector *point;
	s_vector *temp;
	float denom;
	float k[2];
	float t;
	float distance;
	float diago;

	t = 0;
	denom = -(product_vectors(*object->orientation, *object->center));
	k[0] = product_vectors(origin, *object->orientation) + denom;
	k[1] = product_vectors(direction, *object->orientation);
	t = - (k[0] / k[1]);
	if (t <= 0)
		return (0);
	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	diago = object->size * sqrt(2);
	distance = sqrt(pow(point->x - object->center->x, 2) +
					pow(point->y - object->center->y, 2) +
					pow(point->z - object->center->z, 2));
	//printf("distance : %f\n", distance);
	if (distance <= object->size/2 || distance <= diago/2)
	{
		//printf("point : (%f, %f, %f)\n", point->x, point->y, point->z);
		//if (distance > 2.5 || distance < 1.5)
			//printf("distance : %f\n", distance);
		return (t);
	}
	return (0);
}
