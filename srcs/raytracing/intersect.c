/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:17:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 06:27:55 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float		intersect_sphere(s_vector origin,
s_vector direction, s_sphere *object)
{
	float		discriminant;
	float		k[2];
	float		t[2];

	if (!object->difference || !is_equal(object->prev_origin, &origin))
	{
		object->difference = subtract_vectors(origin, *object->center);
		object->calcul_c = product_vectors(*object->difference, *object->difference) - (object->radius * object->radius);
		object->prev_origin = cpy_vector(&origin);
	}
	k[0] = product_vectors(direction, direction);
	k[1] = 2 * product_vectors(*object->difference, direction);
	discriminant = k[1] * k[1] - 4 * k[0] * object->calcul_c;
	if (discriminant < 0)
		return (0);
	t[0] = (- k[1] + sqrt(discriminant)) / (2 * k[0]);
	t[1] = (- k[1] - sqrt(discriminant)) / (2 * k[0]);
	if (t[0] < t[1])
		return (t[0]);
	return (t[1]);
}

float		intersect_plan(s_vector origin, s_vector direction, s_plan *object)
{
	float denom;
	float b;
	float t;

	t = 0;
	if (!object->calcul_a || !is_equal(object->prev_origin, &origin))
	{
		denom = -(product_vectors(*object->normal, *object->point));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	b = product_vectors(direction, *object->normal);
	t = - (object->calcul_a / b);
	return ((t < 0) ? 0 : t);
}

float		intersect_square(s_vector origin, s_vector direction, s_square *object)
{
	s_vector *point;
	s_vector *temp;
	float denom;
	float b;
	float t;
	s_vector *ap;
	float alpha;
	float beta;

	t = 0;
	if (!object->calcul_a || !is_equal(object->prev_origin, &origin))
	{
		denom = -(product_vectors(*object->normal, *object->center));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	b = product_vectors(direction, *object->normal);
	t = - (object->calcul_a / b);
	if (t <= 0)
		return (0);
	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	ap = subtract_vectors(*point, *object->a);
	alpha = product_vectors(*ap, *object->ab) / product_vectors(*object->ab, *object->ab);
	beta = product_vectors(*ap, *object->ac) / product_vectors(*object->ac, *object->ac);
	free(ap);
	free(point);
	if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1)
		return (t);
	return (0);
}

float		intersect_triangle(s_vector origin, s_vector direction, s_triangle *object)
{
	s_vector *point;
	s_vector *temp;
	float denom;
	float b;
	float t;
	s_vector *w;
	float	dot_wu;
	float	dot_wv;
	float r[2];

	t = 0;
	if (!object->calcul_a || !is_equal(object->prev_origin, &origin))
	{
		denom = -(product_vectors(*object->normal, *object->a));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	b = product_vectors(direction, *object->normal);
	t = - (object->calcul_a / b);
	if (t <= 0)
		return (0);
	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	w = subtract_vectors(*point, *object->a);
	dot_wu = product_vectors(*w, *object->u);
	dot_wv = product_vectors(*w, *object->v);
	r[0] = (object->dot_uv * dot_wv - object->dot_vv * dot_wu) / object->calcul_d;
	free(w);
	if (r[0] < 0 || r[0] > 1)
		return (0);
	r[1] = (object->dot_uv * dot_wu - object->dot_uu * dot_wv) / object->calcul_d;
	if (r[1] < 0 || (r[0] + r[1] > 1))
		return (0);
	return (t);
}

float		intersect_cylinder(s_vector origin, s_vector direction, s_cylinder *object)
{
	float calcul_b;
	float a;
	float b;
	float c;
	float delta;
	s_vector *temp;
	s_vector *point;
	float t[2];
	float ret;
	float size;
	float denom;
	float l[2];
	float tt;
	float d[4];
	s_vector *point_tmp;
	s_vector *temp2;

	if (!object->difference || !is_equal(object->prev_origin, &origin))
	{
		object->difference = subtract_vectors(origin, *object->center);
		object->calcul_c = product_vectors(*object->difference, *object->difference);
		object->calcul_d = product_vectors(*object->orientation, *object->difference);
		object->prev_origin = cpy_vector(&origin);

	}
	calcul_b = product_vectors(direction, *object->orientation);
	a = product_vectors(direction, direction) - (calcul_b * calcul_b * object->calcul_a);
	b = 2.0 * (product_vectors(direction, *object->difference)) - (2 * calcul_b * object->calcul_d * object->calcul_a);
	c = object->calcul_c - ((object->diameter / 2.0) * (object->diameter / 2.0)) - ((object->calcul_d * object->calcul_d) * object->calcul_a);
	delta = (b * b) - (4.0 * a * c);
	if (delta < 0)
		return (0);
	t[0] = (- b + sqrt(delta)) / (2.0 * a);
	t[1] = (- b - sqrt(delta)) / (2.0 * a);
	if (t[0] < t[1])
		ret = t[0];
	else
		ret = t[1];
	if (ret == 0)
		return (0);
	size = distance_points(*object->point1, *object->point2);
	temp = multiply_vectors(ret, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	denom = -(product_vectors(*object->orientation, *object->point1));
	l[0] = product_vectors(*point, *object->orientation) + denom;
	l[1] = product_vectors(*object->orientation, *object->orientation);
	tt = - (l[0] / l[1]);
	temp = multiply_vectors(tt, *object->orientation);
	point_tmp = add_vectors(*point, *temp);
	free(temp);
	d[2] = distance_points(*point, *point_tmp);
	free(point_tmp);
	denom = -(product_vectors(*object->orientation, *object->point2));
	l[0] = product_vectors(*point, *object->orientation) + denom;
	temp2 = multiply_vectors(-1, *object->orientation);
	l[1] = product_vectors(*temp2, *object->orientation);
	tt = - (l[0] / l[1]);
	temp = multiply_vectors(tt, *temp2);
	point_tmp = add_vectors(*point, *temp);
	free(temp2);
	free(temp);
	d[3] = distance_points(*point, *point_tmp);
	free(point_tmp);
	free(point);

	tt = 0;
	denom = -(product_vectors(*object->orientation, *object->point1));
	l[0] = product_vectors(origin, *object->orientation) + denom;
	l[1] = product_vectors(direction, *object->orientation);
	tt = - (l[0] / l[1]);
	if (tt > 0)
	{
		temp = multiply_vectors(tt, direction);
		point = add_vectors(origin, *temp);
		free(temp);
		d[0] = distance_points(*point, *object->point1);
		d[1] = distance_points(*point, origin);
		if (d[0] < object->diameter / 2)
		{
			if (!(d[2] > size || d[3] > size))
				return (ret);
			free(point);
			return (tt);
		}
		free(point);
	}
	tt = 0;
	denom = -(product_vectors(*object->orientation, *object->point2));
	l[0] = product_vectors(origin, *object->orientation) + denom;
	l[1] = product_vectors(direction, *object->orientation);
	tt = - (l[0] / l[1]);
	if (tt > 0)
	{
		temp = multiply_vectors(tt, direction);
		point = add_vectors(origin, *temp);
		free(temp);
		d[0] = distance_points(*point, *object->point2);
		d[1] = distance_points(*point, origin);
		if (d[0] < object->diameter / 2)
		{
			if (!(d[2] > size || d[3] > size))
				return (ret);
			free(point);
			return (tt);
		}
		free(point);
	}
	if ((d[2] > size || d[3] > size))
		return (0);
	return (ret);
}
