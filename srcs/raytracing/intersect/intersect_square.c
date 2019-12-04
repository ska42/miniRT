/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:01:49 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:19:47 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float		intersect_square2(float t, t_vector origin, t_vector direction,
t_square *object)
{
	t_vector	*point;
	t_vector	*temp;
	t_vector	*ap;
	float		alpha;
	float		beta;

	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	ap = subtract_vectors(*point, *object->a);
	alpha = product_vectors(*ap, *object->ab) /
product_vectors(*object->ab, *object->ab);
	beta = product_vectors(*ap, *object->ac) /
product_vectors(*object->ac, *object->ac);
	free(ap);
	free(point);
	if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1)
		return (t);
	return (0);
}

float		intersect_square(t_vector origin, t_vector direction,
t_square *object)
{
	float denom;
	float alpha;
	float beta;

	beta = 0;
	if (!object->prev_origin || !is_equal(object->prev_origin, &origin))
	{
		if (object->prev_origin)
			free(object->prev_origin);
		denom = -(product_vectors(*object->normal, *object->center));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	alpha = product_vectors(direction, *object->normal);
	beta = -(object->calcul_a / alpha);
	if (beta <= 0)
		return (0);
	return (intersect_square2(beta, origin, direction, object));
}
