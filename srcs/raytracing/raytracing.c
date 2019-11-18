/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:13:11 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/18 05:09:35 by lmartin          ###   ########.fr       */
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

	temp = NULL;
	object = objects->object;
	if (objects->type == TYPE_SPHERE)
		temp = subtract_vectors(*l_vectors->point,
			*(((s_sphere *)object)->center));
	else if (objects->type == TYPE_PLAN)
	{
		temp = subtract_vectors(*l_vectors->point,
			(*l_vectors->point));
	}
	else if (objects->type == TYPE_SQUARE)
	{
		temp = subtract_vectors(*l_vectors->point,
			*(((s_square *)object)->center));
	}
	else if (objects->type == TYPE_TRIANGLE)
	{
		temp = subtract_vectors(*l_vectors->point,
			*(((s_triangle *)object)->a));
	}
	else if (objects->type == TYPE_CYLINDER)
		temp = subtract_vectors(*l_vectors->point,
			*(((s_cylinder *)object)->center));
	l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
	free(temp);
	if (objects->type == TYPE_SPHERE)
	{
		l_vectors->shiny = ((s_sphere *)object)->shiny;
		temp = color_to_rgb(((s_sphere *)object)->color);
	}
	else if (objects->type == TYPE_PLAN)
	{
		l_vectors->shiny = ((s_plan *)object)->shiny;
		temp = color_to_rgb(((s_plan *)object)->color);
	}
	else if (objects->type == TYPE_SQUARE)
	{
		l_vectors->shiny = ((s_square *)object)->shiny;
		temp = color_to_rgb(((s_square *)object)->color);
	}
	else if (objects->type == TYPE_TRIANGLE)
	{
		l_vectors->shiny = ((s_triangle *)object)->shiny;
		temp = color_to_rgb(((s_triangle *)object)->color);
	}
	else if (objects->type == TYPE_CYLINDER)
	{
		l_vectors->shiny = ((s_cylinder *)object)->shiny;
		temp = color_to_rgb(((s_cylinder *)object)->color);
	}
	new_color = multiply_vectors(compute_lightning(l_vectors,
lights, scene), *temp);
	free(temp);
	rearrange_rgb(new_color);
	ret_color = rgb_to_color(new_color);
	free(new_color);
	return (ret_color);
}

int			setup_l_vectors_and_calculate(s_lstobjects *closest_object,
s_vector direction, float closest_t, s_scene *scene)
{
	int						final_color;
	s_lightning_vectors		*l_vectors;
	s_vector				*temp;

	final_color = 0;
	if (!(l_vectors = malloc(sizeof(s_lightning_vectors))))
		return (-1);
	temp = multiply_vectors(closest_t, direction);
	l_vectors->point = add_vectors(*((s_camera *)scene->cameras->object)->origin, *(temp));
	free(temp);
	l_vectors->view = multiply_vectors(-1, direction);
	final_color = calculate_new_color(closest_object,
scene->lights, l_vectors, scene);
	if (closest_object->type == TYPE_SPHERE && (((s_sphere *)closest_object->object)->reflective > 0
	&& scene->depth > 0))
			final_color = color_with_reflect(closest_object, scene,
l_vectors, final_color);
	else if (closest_object->type == TYPE_PLAN && (((s_plan *)closest_object->object)->reflective > 0
	&& scene->depth > 0))
		final_color = color_with_reflect(closest_object, scene,
l_vectors, final_color);
	else if (closest_object->type == TYPE_SQUARE && (((s_square *)closest_object->object)->reflective > 0
	&& scene->depth > 0))
		final_color = color_with_reflect(closest_object, scene,
l_vectors, final_color);
	else if (closest_object->type == TYPE_TRIANGLE && (((s_triangle *)closest_object->object)->reflective > 0
	&& scene->depth > 0))
		final_color = color_with_reflect(closest_object, scene,
	l_vectors, final_color);
	else if (closest_object->type == TYPE_CYLINDER && (((s_cylinder *)closest_object->object)->reflective > 0
	&& scene->depth > 0))
		final_color = color_with_reflect(closest_object, scene,
	l_vectors, final_color);
	free(l_vectors->point);
	free(l_vectors->normal);
	free(l_vectors->view);
	free(l_vectors);
	return (final_color);
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
	//printf("O (%f, %f, %f)\n", origin.x, origin.y, origin.z);
	//printf("D (%f, %f, %f)\n", direction.x, direction.y, direction.z);
	while (objects)
	{
		if (objects->type == TYPE_SPHERE)
			t_temp = intersect_sphere(origin, direction, objects->object);
		else if (objects->type == TYPE_PLAN)
			t_temp = intersect_plan(origin, direction, objects->object);
		else if (objects->type == TYPE_SQUARE)
			t_temp = intersect_square(origin, direction, objects->object);
		else if (objects->type == TYPE_TRIANGLE)
			t_temp = intersect_triangle(origin, direction, objects->object);
		else if (objects->type == TYPE_CYLINDER)
			t_temp = intersect_cylinder(origin, direction, objects->object);
		//printf("t_temp %f\n", t_temp);
		//printf("t_min %f\n", scene->t_min);
		//printf("t_max %f\n", scene->t_max);
		if (t_temp > scene->t_min && (t_temp < scene->t_max ||
scene->t_max == -1) && (t_temp < closest_t|| closest_t == -1))
		{
					//printf("yes\n");
			closest_t = t_temp;
			*closest_object = objects;
		}
		scene->t_max = -1;
		objects = objects->next;
	}
	return (closest_t);
}

int			trace_ray(s_vector direction, s_scene *scene)
{
	float					closest_t;
	s_lstobjects			*closest_object;
	int						color;

	closest_t = closest_intersection(*(((s_camera *)scene->cameras->object)->origin), direction,
scene, &closest_object);
	if (!closest_object)
		return (scene->background_color);
		//printf("wlhn\n");
	color = setup_l_vectors_and_calculate(closest_object,
direction, closest_t, scene);
	return (color);
}
