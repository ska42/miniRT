/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:29:56 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/24 00:16:38 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	calcul_shiny(s_lightning_vectors *l_vectors, s_light *light,
float length_v, s_vector *vec_l)
{
	float		r_dot_v;
	s_vector	*vec_r;
	s_vector	*temp;
	float		intensity;

	intensity = 0;
	temp = multiply_vectors(2.0 * product_vectors(*l_vectors->normal,
*vec_l), *l_vectors->normal);
	vec_r = subtract_vectors(*temp, *vec_l);
	free(temp);
	r_dot_v = product_vectors(*vec_r, *l_vectors->view);
	if (r_dot_v > 0)
		intensity += light->intensity * pow(r_dot_v / (length_vectors(*vec_r)
* length_v), l_vectors->shiny);
	free(vec_r);
	return (intensity);
}

s_vector	*type_light(s_lightning_vectors *l_vectors,
s_light *light, s_scene *scene)
{
	s_vector *vec_l;

	vec_l = NULL;
	if (light->type == TYPE_POINT)
	{
		vec_l = subtract_vectors(*light->vector, *l_vectors->point);
		scene->t_max = 1;
	}
	else if (light->type == TYPE_DIRECTIONAL)
	{
		vec_l = light->vector;
		scene->t_max = -1;
	}
	scene->t_min = 0.001;
	return (vec_l);
}

float	compute_special_lights(s_lightning_vectors *l_vectors,
s_light *light, s_scene *scene, s_lstobjects *objects)
{
	float			intensity;
	float			n_dot_l;
	float			length_v;
	s_vector		*vec_l;
	s_vector		*temp;
	s_lstobjects	*shadow_obj;
	void			*object;
	s_vector		direction;

	intensity = 0;
	object = objects->object;
	length_v = length_vectors(*l_vectors->view);
	vec_l = type_light(l_vectors, light, scene);
	direction = *multiply_vectors(-1, *l_vectors->view);
	closest_intersection(*l_vectors->point, *vec_l, scene, &shadow_obj);
	if (!shadow_obj)
	{
		free(l_vectors->normal);
		float denom;
		float k[4];
		float t;
		s_vector *point;
		s_vector *temp2;

		temp2 = NULL;
		t = 0;
		if (objects->type == TYPE_SPHERE)
		{
			temp = subtract_vectors(*l_vectors->point,
				*(((s_sphere *)object)->center));
			l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
			free(temp);
		}
		else if (objects->type == TYPE_CYLINDER)
		{

			temp = subtract_vectors(*l_vectors->point, *(((s_cylinder *)object)->center));
			l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
			free(temp);

			if (product_vectors(*((s_cylinder *)object)->orientation, direction) < 0)
			{
				// SI FACE DESSUS OU DESSOUS
				denom = -(product_vectors(*((s_cylinder *)object)->orientation, *((s_cylinder *)object)->point1));
				k[0] = product_vectors(*((s_camera *)scene->cameras->object)->origin, *((s_cylinder *)object)->orientation) + denom;
				k[1] = product_vectors(direction, *((s_cylinder *)object)->orientation);
				t = - (k[0] / k[1]);
				if (t > 0)
				{
					temp = multiply_vectors(t, direction);
					point = add_vectors(*((s_camera *)scene->cameras->object)->origin, *temp);
					free(temp);
					k[0] = distance_points(*point, *((s_cylinder *)object)->point1);
					free(point);
					if (k[0] < ((s_cylinder *)object)->diameter / 2)
					{
						temp2 = multiply_vectors(-1, *((s_plan *)object)->normal);
						denom = -(product_vectors(*((s_plan *)object)->normal, *((s_plan *)object)->point));
						k[0] = product_vectors(*light->vector, *((s_plan *)object)->normal) + denom;
						k[1] = product_vectors(*temp2, *((s_plan *)object)->normal);
						t = - (k[0] / k[1]);
						temp = multiply_vectors(t, *temp2);
						point = add_vectors(*light->vector, *temp);
						free(temp);
						temp = subtract_vectors(*light->vector, *point);
						l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
						free(temp);
						free(point);
					}
				}
			}
			else if (product_vectors(*((s_cylinder *)object)->orientation, direction) > 0)
			{
				denom = -(product_vectors(*((s_cylinder *)object)->orientation, *((s_cylinder *)object)->point2));
				k[0] = product_vectors(*((s_camera *)scene->cameras->object)->origin, *((s_cylinder *)object)->orientation) + denom;
				k[1] = product_vectors(direction, *((s_cylinder *)object)->orientation);
				t = - (k[0] / k[1]);
				if (t > 0)
				{

					temp = multiply_vectors(t, direction);
					point = add_vectors(*((s_camera *)scene->cameras->object)->origin, *temp);
					free(temp);
					k[0] = distance_points(*point, *((s_cylinder *)object)->point2);
					free(point);
					if (k[0] < ((s_cylinder *)object)->diameter / 2)
					{
						temp2 = multiply_vectors(-1, *((s_plan *)object)->normal);
						denom = -(product_vectors(*((s_plan *)object)->normal, *((s_plan *)object)->point));
						k[0] = product_vectors(*light->vector, *((s_plan *)object)->normal) + denom;
						k[1] = product_vectors(*temp2, *((s_plan *)object)->normal);
						t = - (k[0] / k[1]);
						temp = multiply_vectors(t, *temp2);
						point = add_vectors(*light->vector, *temp);
						free(temp);
						temp = subtract_vectors(*light->vector, *point);
						l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
						free(temp);
						free(point);
					}
				}
			}
			free(temp2);
		}
		else if (objects->type == TYPE_PLAN || objects->type == TYPE_TRIANGLE || objects->type == TYPE_SQUARE)
		{
			if (objects->type == TYPE_PLAN)
			{
				temp2 = multiply_vectors(-1, *((s_plan *)object)->normal);
				denom = -(product_vectors(*((s_plan *)object)->normal, *((s_plan *)object)->point));
				k[0] = product_vectors(*light->vector, *((s_plan *)object)->normal) + denom;
				k[1] = product_vectors(*temp2, *((s_plan *)object)->normal);
			}
			else if (objects->type == TYPE_TRIANGLE)
			{
				s_vector *normal;
				s_vector *u;
				s_vector *v;
				u = subtract_vectors(*((s_triangle *)object)->b, *((s_triangle *)object)->a);
				v = subtract_vectors(*((s_triangle *)object)->c, *((s_triangle *)object)->a);
				normal = cross(*u, *v);
				temp2 = multiply_vectors(-1, *normal);
				denom = -(product_vectors(*normal, *((s_triangle *)object)->a));
				k[0] = product_vectors(*light->vector, *normal) + denom;
				k[1] = product_vectors(*temp2, *normal);
				free(normal);
				free(u);
				free(v);
			}
			else if (objects->type == TYPE_SQUARE)
			{
				temp2 = multiply_vectors(-1, *((s_square *)object)->orientation);
				denom = -(product_vectors(*((s_square *)object)->orientation, *((s_square *)object)->center));
				k[0] = product_vectors(*light->vector, *((s_square *)object)->orientation) + denom;
				k[1] = product_vectors(*temp2, *((s_square *)object)->orientation);
			}
			t = - (k[0] / k[1]);
			temp = multiply_vectors(t, *temp2);
			point = add_vectors(*light->vector, *temp);
			free(temp);
			temp = subtract_vectors(*light->vector, *point);
			l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
			free(temp);
			free(point);
		}
		n_dot_l = product_vectors(*l_vectors->normal, *vec_l);
		if (n_dot_l > 0)
		{
			intensity += ((light->intensity * n_dot_l) /
		((length_vectors(*l_vectors->normal) * length_vectors(*vec_l))));
		}
		if (l_vectors->shiny != -1)
			intensity += calcul_shiny(l_vectors, light, length_v, vec_l);
	}
	if (light->type == TYPE_POINT)
		free(vec_l);
	return (intensity);
}

s_vector	*set_shiny_and_get_color(s_lightning_vectors *l_vectors, s_lstobjects *objects)
{
	if (objects->type == TYPE_SPHERE)
	{
		l_vectors->shiny = ((s_sphere *)objects->object)->shiny;
		return (((s_sphere *)objects->object)->color);
	}
	else if (objects->type == TYPE_PLAN)
	{
		l_vectors->shiny = ((s_plan *)objects->object)->shiny;
		return (((s_plan *)objects->object)->color);
	}
	else if (objects->type == TYPE_SQUARE)
	{
		l_vectors->shiny = ((s_square *)objects->object)->shiny;
		return (((s_square *)objects->object)->color);
	}
	else if (objects->type == TYPE_TRIANGLE)
	{
		l_vectors->shiny = ((s_triangle *)objects->object)->shiny;
		return (((s_triangle *)objects->object)->color);
	}
	else if (objects->type == TYPE_CYLINDER)
	{
		l_vectors->shiny = ((s_cylinder *)objects->object)->shiny;
		return (((s_cylinder *)objects->object)->color);
	}
	return (NULL);
}

int		compute_lightning(s_lightning_vectors *l_vectors,
s_lstobjects *lights, s_scene *scene, s_lstobjects *objects)
{
	float		intensity;
	int			ret_color;
	s_vector	*color;
	s_vector	*obj_color;
	s_vector	*new_color;
	s_vector	*actual_color;

	obj_color = set_shiny_and_get_color(l_vectors, objects);
	actual_color = new_vector(0, 0, 0);
	intensity = 0;
	while(lights)
	{
		intensity = 0;
		if (((s_light *)lights->object)->type == TYPE_AMBIENT)
		{
			intensity += ((s_light *)lights->object)->intensity;
			new_color = cpy_vector(((s_light *)lights->object)->color);
			color = new_vector(actual_color->x + ((new_color->x + obj_color->x) * intensity),
		actual_color->y + ((new_color->y + obj_color->y) * intensity),
		actual_color->z + ((new_color->z + obj_color->z) * intensity));
		}
		else
		{
			intensity += compute_special_lights(l_vectors, (s_light *)lights->object, scene, objects);
			new_color = new_vector(((((s_light *)lights->object)->color->x * (intensity / scene->total_intensity)) - obj_color->x)
			,((((s_light *)lights->object)->color->y * (intensity / scene->total_intensity)) -  obj_color->y)
			,((((s_light *)lights->object)->color->z * (intensity / scene->total_intensity)) - obj_color->z));
			color = new_vector(actual_color->x + (obj_color->x + (new_color->x)),
		actual_color->y + (obj_color->y + (new_color->y)),
		actual_color->z + (obj_color->z + (new_color->z)));
		}
		free(new_color);
		rearrange_rgb(color);
		free(actual_color);
		actual_color = cpy_vector(color);
		free(color);
		lights = lights->next;
	}
	ret_color = rgb_to_color(actual_color);
	free(actual_color);
	return (ret_color);
}
