/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:17:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:55:41 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		intersect_global(t_vector origin, t_vector direction,
t_lstobjects *objects)
{
	float	t;

	t = 0;
	if (objects->type == TYPE_SPHERE)
		t = intersect_sphere(origin, direction, objects->object);
	else if (objects->type == TYPE_PLAN)
		t = intersect_plan(origin, direction, objects->object);
	else if (objects->type == TYPE_SQUARE)
		t = intersect_square(origin, direction, objects->object);
	else if (objects->type == TYPE_TRIANGLE)
		t = intersect_triangle(origin, direction, objects->object);
	else if (objects->type == TYPE_CYLINDER)
		t = intersect_cylinder(origin, direction, objects->object);
	return (t);
}

void		init_cylinder_intersect_cylinder(t_vector origin,
t_cylinder *object)
{
	if (!object->prev_origin || !is_equal(object->prev_origin, &origin))
	{
		if (object->difference)
			free(object->difference);
		if (object->prev_origin)
			free(object->prev_origin);
		object->difference = subtract_vectors(origin, *object->center);
		object->calcul_c = product_vectors(*object->difference,
*object->difference);
		object->calcul_d = product_vectors(*object->orientation,
*object->difference);
		object->prev_origin = cpy_vector(&origin);
	}
}
