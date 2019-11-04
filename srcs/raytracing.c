/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:13:11 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 02:52:13 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int			calculate_new_color(s_lstobjects *objects, s_lstobjects *lights,
s_lightning_vectors *l_vectors, s_scene *scene)
{
	int			ret_color;
	void 		*object;
	s_vector	*new_color;
	s_vector	*temp;

	object = objects->object;
	temp = subtract_vectors(*l_vectors->point,
*(((s_sphere *)object)->center));
	l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
	free(temp);
	if (objects->type == TYPE_SPHERE)
	{
		l_vectors->shiny = ((s_sphere *)object)->shiny;
		temp = color_to_rgb(((s_sphere *)object)->color);
		new_color = multiply_vectors(compute_lightning(l_vectors,
lights, scene), *temp);
		free(temp);
		rearrange_rgb(new_color);
		ret_color = rgb_to_color(new_color);
		free(new_color);
		return (ret_color);
	}
	return (scene->background_color);
}

int			setup_l_vectors_and_calculate(s_lstobjects *closest_object,
s_vector direction, float closest_t, s_scene *scene)
{
	int						final_color;
	s_lightning_vectors		*l_vectors;
	s_vector				*temp;

	final_color = 0;
	l_vectors = malloc(sizeof(s_lightning_vectors));
	temp = multiply_vectors(closest_t, direction);
	l_vectors->point = add_vectors(*scene->origin, *(temp));
	free(temp);
	l_vectors->view = multiply_vectors(-1, direction);
	final_color = calculate_new_color(closest_object,
scene->lights, l_vectors, scene);
	if (((s_sphere *)closest_object->object)->reflective > 0
&& scene->depth > 0)
		final_color = color_with_reflect(closest_object, scene,
l_vectors, final_color);
	printf("free_all\n");
	free(l_vectors->point);
	free(l_vectors->normal);
	free(l_vectors->view);
	free(l_vectors);
	printf("free_end_all\n");
	return (final_color);
}

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

float		closest_intersection(s_vector origin, s_vector direction,
s_scene *scene, s_lstobjects **closest_object)
{
	float					t_temp;
	float					closest_t;
	s_lstobjects			*objects;

	*closest_object = NULL;
	closest_t = -1;
	objects = scene->objects;
	while (objects)
	{
		if (objects->type == TYPE_SPHERE)
			t_temp = intersect_sphere(origin,
direction, objects->object);
		if (t_temp > scene->t_min && (t_temp < scene->t_max ||
scene->t_max == -1) && (t_temp < closest_t|| closest_t == -1))
		{
			closest_t = t_temp;
			*closest_object = objects;
		}
		objects = objects->next;
	}
	return (closest_t);
}

int			trace_ray(s_vector direction, s_scene *scene)
{
	float					closest_t;
	s_lstobjects			*closest_object;
	int						color;

	printf("trace_ray\n");
	closest_t = closest_intersection(*scene->origin, direction,
scene, &closest_object);
	if (!closest_object)
		return (scene->background_color);
	color = setup_l_vectors_and_calculate(closest_object,
direction, closest_t, scene);
	printf("end_trace_ray\n");
	return (color);
}
