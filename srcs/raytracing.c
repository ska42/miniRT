/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:13:11 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/01 08:25:13 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	compute_lightning(s_vector *point, s_vector *normal, s_lstobjects *lights)
{
	int			i;
	float		intensity;
	s_light		light;
	s_vector	*vec_l;
	float		n_dot_l;
	float		length_n;

	length_n = length_vectors(*normal);
	intensity = 0;
	i = 0;
	while (lights)
	{
		light = (*(s_light *)lights->object);
		if (light.type == TYPE_AMBIENT)
			intensity += light.intensity;
		else
		{
			if (light.type == TYPE_POINT)
				vec_l = subtract_vectors(*light.vector, *point);
			else if (light.type == TYPE_DIRECTIONAL)
				vec_l = light.vector;
			n_dot_l = product_vectors(*normal, *vec_l);
			if (n_dot_l > 0)
				intensity += light.intensity * n_dot_l / (1 * length_vectors(*vec_l));
		}
		lights = lights->next;
	}
	return (intensity);
}

float	intersect_sphere(s_vector origin, s_vector direction, s_sphere *object)
{
	s_vector	*difference;
	float		discriminant;
	float		k[3];
	float		t[2];

	difference = new_vector(origin.x - object->center->x, origin.y - object->center->y, origin.z - object->center->z);
	k[0] = product_vectors(direction, direction);
	k[1] = 2 * product_vectors(*difference, direction);
	k[2] = product_vectors(*difference, *difference) - (object->radius * object->radius);
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

int		trace_ray(s_vector origin, s_vector direction, s_lstobjects *objects, float t_min_max[2], s_lstobjects *lights)
{
	int		ret_color;
	int		type;
	float	t_temp;
	float	closest_t;
	void	*closest_object;
	s_vector	*point;
	s_vector	*normal;
	s_vector	*color;
	s_vector	*new_color;

	closest_object = NULL;
	closest_t = -1;
	type = -1;
	while (objects)
	{
		if (objects->type == TYPE_SPHERE)
			t_temp = intersect_sphere(origin, direction, objects->object);
		if (t_temp > t_min_max[0] && (t_temp < t_min_max[1] || t_min_max[1] == -1) && (t_temp < closest_t|| closest_t == -1))
		{
			type = objects->type;
			closest_t = t_temp;
			closest_object = objects->object;
		}
		objects = objects->next;
	}
	if (!closest_object)
		return (BACKGROUND_COLOR);
	point = add_vectors(origin, *(multiply_vectors(closest_t, direction)));
	normal = subtract_vectors(*point, *(((s_sphere *)closest_object)->center));
	normal = multiply_vectors(1 / length_vectors(*normal), *normal);
	if (type == TYPE_SPHERE)
	{
		color = color_to_rgb(((s_sphere *)closest_object)->color);
		new_color = multiply_vectors(compute_lightning(point, normal, lights), *color);
		free(color);
		ret_color = rgb_to_color(new_color);
		free(new_color);
		return (ret_color);
	}
	return (BACKGROUND_COLOR);
}
