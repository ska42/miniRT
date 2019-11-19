/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:29:56 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/19 02:50:18 by lmartin          ###   ########.fr       */
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
		//printf("vec_l(%f, %f, %f)\n", vec_l->x, vec_l->y, vec_l->z);
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
	float			test;
	s_vector		*vec_l;
	s_vector		*temp;
	s_lstobjects	*shadow_obj;
	void			*object;

	intensity = 0;
	object = objects->object;
	length_v = length_vectors(*l_vectors->view);
	vec_l = type_light(l_vectors, light, scene);
	//printf("LEN %f\n", length_vectors(*vec_l));
	test = closest_intersection(*l_vectors->point, *vec_l, scene, &shadow_obj);
	if (!shadow_obj)
	{
		if (objects->type == TYPE_PLAN || objects->type == TYPE_TRIANGLE || objects->type == TYPE_SQUARE)
		{
			free(l_vectors->normal);
			float denom;
			float k[2];
			float t;
			s_vector *point;
			s_vector *temp2;

			t = 0;
			if (objects->type == TYPE_PLAN)
			{
				temp2 = multiply_vectors(-1, *((s_plan *)object)->normal);;
				denom = -(product_vectors(*((s_plan *)object)->normal, *((s_plan *)object)->point));
				k[0] = product_vectors(*light->vector, *((s_plan *)object)->normal) + denom;
				k[1] = product_vectors(*temp2, *((s_plan *)object)->normal);
			}
			if (objects->type == TYPE_TRIANGLE)
			{
				s_vector *normal;
				s_vector *u;
				s_vector *v;
				u = subtract_vectors(*((s_triangle *)object)->b, *((s_triangle *)object)->a);
				v = subtract_vectors(*((s_triangle *)object)->c, *((s_triangle *)object)->a);
				normal = cross(*u, *v);

				temp2 = multiply_vectors(-1, *normal);;
				denom = -(product_vectors(*normal, *((s_triangle *)object)->a));
				k[0] = product_vectors(*light->vector, *normal) + denom;
				k[1] = product_vectors(*temp2, *normal);
			}
			if (objects->type == TYPE_SQUARE)
			{
				temp2 = multiply_vectors(-1, *((s_square *)object)->orientation);;
				denom = -(product_vectors(*((s_square *)object)->orientation, *((s_square *)object)->center));
				k[0] = product_vectors(*light->vector, *((s_square *)object)->orientation) + denom;
				k[1] = product_vectors(*temp2, *((s_square *)object)->orientation);
			}
			t = - (k[0] / k[1]);
			temp = multiply_vectors(t, *temp2);
			point = add_vectors(*light->vector, *temp);
			//printf("point (%f, %f, %f)\n", point->x, point->y, point->z);
			free(temp);
			temp = subtract_vectors(*light->vector, *point);
			l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
			free(temp);
			free(point);
		}
		n_dot_l = product_vectors(*l_vectors->normal, *vec_l);
		//dot(N, L) * lightIntensity / distanceToLight^2;
		if (n_dot_l > 0)
		{
			//printf("intensity * n_dot_l : %f\n", light->intensity * n_dot_l);
			intensity += ((light->intensity * n_dot_l) /
		((length_vectors(*l_vectors->normal) * length_vectors(*vec_l))));
		}
		if (l_vectors->shiny != -1)
			intensity += calcul_shiny(l_vectors, light, length_v, vec_l);
	}
	//if (intensity)
		//printf("intensity : %f\n", intensity);
	if (light->type == TYPE_POINT)
		free(vec_l);
	return (intensity);
}

float	compute_lightning(s_lightning_vectors *l_vectors,
s_lstobjects *lights, s_scene *scene, s_lstobjects *objects)
{
	float		intensity;
	s_light		*light;

	intensity = 0;
	while (lights)
	{
		light = ((s_light *)lights->object);
		if (light->type == TYPE_AMBIENT)
			intensity += light->intensity;
		else
			intensity += compute_special_lights(l_vectors, light, scene, objects);
		lights = lights->next;
	}
	//printf("intensity : %f\n", intensity);
	return (intensity);
}
