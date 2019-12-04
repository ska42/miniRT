/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:13:11 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 17:24:36 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minirt.h"

int			setup_l_vectors_and_calculate(t_lstobjects *closest_object,
t_vector direction, float closest_t, t_scene *scene)
{
	int						final_color;
	t_lightning_vectors		*l_vectors;
	t_vector				*temp;

	final_color = 0;
	if (!(l_vectors = malloc(sizeof(t_lightning_vectors))))
		print_error_and_exit(-7);
	temp = multiply_vectors(closest_t, direction);
	l_vectors->point = add_vectors(*(
(t_camera *)scene->cameras->object)->origin, *(temp));
	free(temp);
	l_vectors->normal = new_vector(0, 0, 0);
	l_vectors->view = multiply_vectors(-1, direction);
	final_color = compute_lightning(l_vectors, scene->lights,
scene, closest_object);
	if (scene->depth > 0 && closest_object->reflective > 0)
		final_color = color_with_reflect(closest_object, scene,
l_vectors, final_color);
	free_l_vectors(l_vectors);
	return (final_color);
}

float		closest_intersection(t_vector origin, t_vector direction,
t_scene *scene, t_lstobjects **closest_object)
{
	float					t_temp;
	float					closest_t;
	t_lstobjects			*objects;

	*closest_object = NULL;
	closest_t = -1;
	objects = scene->objects;
	while (objects)
	{
		t_temp = intersect_global(origin, direction, objects);
		if (t_temp > scene->t_min && (t_temp < scene->t_max ||
scene->t_max == -1) && (t_temp < closest_t || closest_t == -1))
		{
			closest_t = t_temp;
			*closest_object = objects;
		}
		scene->t_max = -1;
		objects = objects->next;
	}
	return (closest_t);
}

int			trace_ray(t_vector direction, t_scene *scene)
{
	float					closest_t;
	t_lstobjects			*closest_object;
	int						color;

	closest_t = closest_intersection(*(((t_camera *)scene->cameras->object)
->origin), direction, scene, &closest_object);
	if (!closest_object)
		return (scene->background_color);
	color = setup_l_vectors_and_calculate(closest_object, direction,
closest_t, scene);
	return (color);
}
