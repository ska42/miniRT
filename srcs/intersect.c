/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:17:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 00:55:05 by lmartin          ###   ########.fr       */
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
	//float distance;
	//float diago;
	s_vector *ab;
	s_vector *ac;
	s_vector *ap;
	s_vector *normal;
	float alpha;
	float beta;

	ab = subtract_vectors(*object->b, *object->a);
	ac = subtract_vectors(*object->c, *object->a);
	normal = new_vector(ab->y * ac->z - ab->z * ac->y, ab->z * ac ->z - ab->x * ac->z, ab->x * ac->y - ab->y * ac->x);
	t = 0;
	denom = -(product_vectors(*normal, *object->center));
	k[0] = product_vectors(origin, *normal) + denom;
	k[1] = product_vectors(direction, *normal);
	t = - (k[0] / k[1]);
	if (t <= 0)
		return (0);
	//printf("t : %f\n",t);
	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	//printf("temp : (%f, %f, %f)\n", temp->x, temp->y, temp->z);
	ap = subtract_vectors(*point, *object->a);
	//printf("ab : (%f, %f, %f)\n", ab->x, ab->y, ab->z);
	//printf("ac : (%f, %f, %f)\n", ac->x, ac->y, ac->z);
	//printf("ap : (%f, %f, %f)\n", ap->x, ap->y, ap->z);
	alpha = product_vectors(*ap, *ab) / product_vectors(*ab, *ab);
	beta = product_vectors(*ap, *ac) / product_vectors(*ac, *ac);
	//printf("alpha - beta : %f, %f\n", alpha, beta);
	if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1)
		return (t);
 	//printf("d[0] %f\n", d[0]);
	//printf("d[1] %f\n", d[1]);
	//printf("point (%f, %f, %f)\n", point->x, point->y, point->z);
	//printf("d[2] %f\n", d[2]);
		//printf("point : (%f, %f, %f)\n", point->x, point->y, point->z);
	//if (distance > 2.5 || distance < 1.5)
		//printf("distance : %f\n", distance);
	return (0);
}
