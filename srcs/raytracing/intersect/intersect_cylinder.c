/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:00:17 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 18:28:43 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		intersect_cylinder5(float d[8], t_vector origin, t_vector direction,
t_cylinder *o)
{
	t_vector	*temp;
	t_vector	*point;
	float		denom;
	float		l[2];

	denom = -(product_vectors(*o->orientation, *o->point2));
	l[0] = product_vectors(origin, *o->orientation) + denom;
	l[1] = product_vectors(direction, *o->orientation);
	d[5] = -(l[0] / l[1]);
	if (d[5] > 0)
	{
		temp = multiply_vectors(d[5], direction);
		point = add_vectors(origin, *temp);
		free(temp);
		d[0] = distance_points(*point, *o->point2);
		d[1] = distance_points(*point, origin);
		free(point);
		if (d[0] < o->diameter / 2 && (!(d[2] > o->height || d[3] > o->height)))
			return (d[4]);
		if (d[0] < o->diameter / 2)
			return (d[5]);
	}
	if ((d[2] > o->height || d[3] > o->height))
		return (0);
	return (d[4]);
}

float		intersect_cylinder4(float d[8], t_vector origin, t_vector direction,
t_cylinder *o)
{
	t_vector	*temp;
	t_vector	*point;
	float		denom;
	float		l[2];

	denom = -(product_vectors(*o->orientation, *o->point1));
	l[0] = product_vectors(origin, *o->orientation) + denom;
	l[1] = product_vectors(direction, *o->orientation);
	d[5] = -(l[0] / l[1]);
	if (d[5] > 0)
	{
		temp = multiply_vectors(d[5], direction);
		point = add_vectors(origin, *temp);
		free(temp);
		d[0] = distance_points(*point, *o->point1);
		d[1] = distance_points(*point, origin);
		free(point);
		if (d[0] < o->diameter / 2 && (!(d[2] > o->height || d[3] > o->height)))
			return (d[4]);
		if (d[0] < o->diameter / 2)
			return (d[5]);
	}
	return (intersect_cylinder5(d, origin, direction, o));
}

float		intersect_cylinder3(float d[8], t_vector origin, t_vector direction,
t_cylinder *o)
{
	t_vector	*temp[2];
	t_vector	*point;
	float		denom;
	t_vector	*point_tmp;
	float		tt;

	temp[0] = multiply_vectors(d[4], direction);
	point = add_vectors(origin, *temp[0]);
	denom = -(product_vectors(*o->orientation, *o->point2));
	d[5] = product_vectors(*point, *o->orientation) + denom;
	temp[1] = multiply_vectors(-1, *o->orientation);
	d[6] = product_vectors(*temp[1], *o->orientation);
	tt = -(d[5] / d[6]);
	temp[0] = multiply_vectors(tt, *temp[1]);
	point_tmp = add_vectors(*point, *temp[0]);
	free(temp[1]);
	free(temp[0]);
	d[3] = distance_points(*point, *point_tmp);
	free(point_tmp);
	free(point);
	return (intersect_cylinder4(d, origin, direction, o));
}

float		intersect_cylinder2(float ret, t_vector origin, t_vector direction,
t_cylinder *object)
{
	t_vector	*temp;
	t_vector	*point;
	float		denom;
	t_vector	*point_tmp;
	float		d[8];

	d[4] = ret;
	temp = multiply_vectors(ret, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	denom = -(product_vectors(*object->orientation, *object->point1));
	d[5] = product_vectors(*point, *object->orientation) + denom;
	d[6] = product_vectors(*object->orientation, *object->orientation);
	d[7] = -(d[5] / d[6]);
	temp = multiply_vectors(d[7], *object->orientation);
	point_tmp = add_vectors(*point, *temp);
	free(temp);
	d[2] = distance_points(*point, *point_tmp);
	free(point_tmp);
	free(point);
	return (intersect_cylinder3(d, origin, direction, object));
}

float		intersect_cylinder(t_vector origin, t_vector direction,
t_cylinder *o)
{
	float calcul_b;
	float d[6];
	float delta;
	float ret;

	init_cylinder_intersect_cylinder(origin, o);
	calcul_b = product_vectors(direction, *o->orientation);
	d[0] = product_vectors(direction, direction) - (calcul_b *
calcul_b * o->calcul_a);
	d[1] = 2.0 * (product_vectors(direction, *o->difference)) -
(2 * calcul_b * o->calcul_d * o->calcul_a);
	d[2] = o->calcul_c - ((o->diameter / 2.0) * (o->diameter / 2.0)) -
((o->calcul_d * o->calcul_d) * o->calcul_a);
	delta = (d[1] * d[1]) - (4.0 * d[0] * d[2]);
	if (delta < 0)
		return (0);
	d[3] = (-d[1] + sqrt(delta)) / (2.0 * d[0]);
	d[4] = (-d[1] - sqrt(delta)) / (2.0 * d[0]);
	if (d[3] < d[4])
		ret = d[3];
	else
		ret = d[4];
	return (intersect_cylinder2(ret, origin, direction, o));
}
