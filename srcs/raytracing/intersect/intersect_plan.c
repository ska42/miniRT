/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:02:36 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:55:29 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		intersect_plan(t_vector origin, t_vector direction, t_plan *object)
{
	float denom;
	float b;
	float t;

	t = 0;
	if (!object->prev_origin || !is_equal(object->prev_origin, &origin))
	{
		if (object->prev_origin)
			free(object->prev_origin);
		denom = -(product_vectors(*object->normal, *object->point));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	b = product_vectors(direction, *object->normal);
	t = -(object->calcul_a / b);
	return ((t < 0) ? 0 : t);
}
