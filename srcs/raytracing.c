/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:13:11 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/02 08:35:48 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	compute_lightning(s_lightning_vectors *l_vectors, s_lstobjects *lights)
{
	float		intensity;
	s_light		*light;
	s_vector	*vec_l;
	s_vector	*vec_r;
	float		n_dot_l;
	float		r_dot_v;
	float		length_n;
	float		length_v;
	s_vector	*temp;

	length_v = length_vectors(*l_vectors->view);
	length_n = length_vectors(*l_vectors->normal);
	intensity = 0;
	while (lights)
	{
		light = ((s_light *)lights->object);
		if (light->type == TYPE_AMBIENT)
			intensity += light->intensity;
		else
		{
			if (light->type == TYPE_POINT)
				vec_l = subtract_vectors(*light->vector, *l_vectors->point);
			else if (light->type == TYPE_DIRECTIONAL)
				vec_l = light->vector;
			n_dot_l = product_vectors(*l_vectors->normal, *vec_l);
			if (n_dot_l > 0)
				intensity += light->intensity * n_dot_l / (1 *
length_vectors(*vec_l));
			if (l_vectors->reflection != -1)
			{
				temp = multiply_vectors(2.0 * product_vectors(*l_vectors->normal, *vec_l), *l_vectors->normal);
				vec_r = subtract_vectors(*temp, *vec_l);
				free(temp);
				r_dot_v = product_vectors(*vec_r, *l_vectors->view);
				if (r_dot_v > 0)
				{
					intensity += light->intensity * pow(r_dot_v / (length_vectors(*vec_r) * length_v), l_vectors->reflection);
				}
				free(vec_r);
			}
			if (light->type == TYPE_POINT)
				free(vec_l);
		}
		lights = lights->next;
	}
	return (intensity);
}

int		calculate_new_color(s_lstobjects *objects, s_lstobjects *lights, s_lightning_vectors *l_vectors)
{
	int			ret_color;
	void 		*object;
	s_vector	*color;
	s_vector	*new_color;
	s_vector	*normal;

	object = objects->object;
	normal = subtract_vectors(*l_vectors->point, *(((s_sphere *)object)->center));
	l_vectors->normal = multiply_vectors(1 / length_vectors(*normal), *normal);
	free(normal);
	if (objects->type == TYPE_SPHERE)
	{
		l_vectors->reflection = ((s_sphere *)object)->reflection;
		color = color_to_rgb(((s_sphere *)object)->color);
		new_color = multiply_vectors(compute_lightning(l_vectors, lights), *color);
		free(l_vectors->normal);
		free(color);
		rearrange_rgb(new_color);
		ret_color = rgb_to_color(new_color);
		free(new_color);
		return (ret_color);
	}
	free(l_vectors->normal);
	return (BACKGROUND_COLOR);
}

float	intersect_sphere(s_vector origin, s_vector direction, s_sphere *object)
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

int		trace_ray(s_vector direction, s_scene *scene)
{
	float					t_temp;
	float					closest_t;
	s_lstobjects			*closest_object;
	s_lightning_vectors		*l_vectors;
	s_lstobjects			*objects;
	int						final_color;
	s_vector				*temp;

	closest_object = NULL;
	closest_t = -1;
	objects = scene->objects;
	while (objects)
	{
		if (objects->type == TYPE_SPHERE)
			t_temp = intersect_sphere(*scene->origin, direction, objects->object);
		if (t_temp > scene->t_min && (t_temp < scene->t_max ||
scene->t_max == -1) && (t_temp < closest_t|| closest_t == -1))
		{
			closest_t = t_temp;
			closest_object = objects;
		}
		objects = objects->next;
	}
	if (!closest_object)
		return (scene->background_color);
	l_vectors = malloc(sizeof(s_lightning_vectors));
	temp = multiply_vectors(closest_t, direction);
	l_vectors->point = add_vectors(*scene->origin, *(temp));
	free(temp);
	l_vectors->view = multiply_vectors(-1, direction);
	final_color = calculate_new_color(closest_object, scene->lights, l_vectors);
	free(l_vectors->point);
	free(l_vectors->view);
	free(l_vectors);
	return (final_color);
}
