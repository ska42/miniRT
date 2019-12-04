/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:00:45 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:55:37 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		intersect_triangle2(float t, t_vector origin, t_vector direction,
t_triangle *object)
{
	t_vector		*temp;
	t_vector		*point;
	float			dot_wv_wu[2];
	t_vector		*w;
	float			r[2];

	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	w = subtract_vectors(*point, *object->a);
	dot_wv_wu[0] = product_vectors(*w, *object->u);
	dot_wv_wu[1] = product_vectors(*w, *object->v);
	r[0] = (object->dot_uv * dot_wv_wu[1] - object->dot_vv *
dot_wv_wu[0]) / object->calcul_d;
	free(w);
	if (r[0] < 0 || r[0] > 1)
		return (0);
	r[1] = (object->dot_uv * dot_wv_wu[0] - object->dot_uu *
dot_wv_wu[1]) / object->calcul_d;
	if (r[1] < 0 || (r[0] + r[1] > 1))
		return (0);
	return (t);
}

float		intersect_triangle(t_vector origin, t_vector direction,
t_triangle *object)
{
	float			denom;
	float			b;
	float			t;

	t = 0;
	if (!object->prev_origin || !is_equal(object->prev_origin, &origin))
	{
		if (object->prev_origin)
			free(object->prev_origin);
		denom = -(product_vectors(*object->normal, *object->a));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	b = product_vectors(direction, *object->normal);
	t = -(object->calcul_a / b);
	if (t <= 0)
		return (0);
	return (intersect_triangle2(t, origin, direction, object));
}
