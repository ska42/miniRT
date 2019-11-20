/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:29:56 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/20 01:14:47 by lmartin          ###   ########.fr       */
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
		free(l_vectors->normal);
		float denom;
		float k[2];
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
			temp = subtract_vectors(*l_vectors->point,
				*(((s_cylinder *)object)->center));
			l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
			free(temp);
		}
		else if (objects->type == TYPE_PLAN || objects->type == TYPE_TRIANGLE || objects->type == TYPE_SQUARE)
		{
			if (objects->type == TYPE_PLAN)
			{
				temp2 = multiply_vectors(-1, *((s_plan *)object)->normal);;
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
				temp2 = multiply_vectors(-1, *normal);;
				denom = -(product_vectors(*normal, *((s_triangle *)object)->a));
				k[0] = product_vectors(*light->vector, *normal) + denom;
				k[1] = product_vectors(*temp2, *normal);
			}
			else if (objects->type == TYPE_SQUARE)
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

int		compute_lightning(s_lightning_vectors *l_vectors,
s_lstobjects *lights, s_scene *scene, s_lstobjects *objects)
{
	float		intensity;
	float		ambient_intensity;
	s_light		*light;
	void		*object;
	s_vector	*color;
	s_vector	*obj_color;
	s_vector	*new_color;
	s_vector	*light_color;
	s_vector	*actual_color;
	s_vector	*ambient_color;

	actual_color = new_vector(0, 0, 0);
	obj_color = NULL;
	object = objects->object;
	if (objects->type == TYPE_SPHERE)
	{
		free(actual_color);
		l_vectors->shiny = ((s_sphere *)object)->shiny;
		obj_color = color_to_rgb(((s_sphere *)object)->color);
	}
	else if (objects->type == TYPE_PLAN)
	{
		free(actual_color);
		l_vectors->shiny = ((s_plan *)object)->shiny;
		obj_color = color_to_rgb(((s_plan *)object)->color);
	}
	else if (objects->type == TYPE_SQUARE)
	{
		free(actual_color);
		l_vectors->shiny = ((s_square *)object)->shiny;
		obj_color = color_to_rgb(((s_square *)object)->color);
	}
	else if (objects->type == TYPE_TRIANGLE)
	{
		free(actual_color);
		l_vectors->shiny = ((s_triangle *)object)->shiny;
		obj_color = color_to_rgb(((s_triangle *)object)->color);
	}
	else if (objects->type == TYPE_CYLINDER)
	{
		free(actual_color);
		l_vectors->shiny = ((s_cylinder *)object)->shiny;
		obj_color = color_to_rgb(((s_cylinder *)object)->color);
	}
	actual_color = new_vector(0, 0, 0);
	//printf("before :actual_color (%f, %f, %f)\n", actual_color->x, actual_color->y, actual_color->z);
	ambient_intensity = 0;
	while (lights)
	{
		intensity = 0;
		light = ((s_light *)lights->object);
		if (light->type == TYPE_AMBIENT)
		{
			ambient_intensity += light->intensity;
			ambient_color = color_to_rgb(light->color);
			new_color = new_vector((obj_color->x * (ambient_color->x * (ambient_intensity / scene->total_intensity)))
			, (obj_color->y * (ambient_color->y * (ambient_intensity / scene->total_intensity)))
			, (obj_color->z * (ambient_color->z * (ambient_intensity / scene->total_intensity))));
			color = new_vector(((new_color->x / 255)),
		((new_color->y / 255)),
		((new_color->z / 255)));
			//color = multiply_vectors(ambient_intensity / scene->total_intensity, *actual_color);
			//printf("new_color (%f, %f, %f)\n", color->x, color->y, color->z);
			//free(actual_color);
			//free(new_color);
			//actual_color = new_vector(color->x, color->y, color->z);
			//free(color);
			rearrange_rgb(color);
			actual_color = new_vector(color->x, color->y, color->z);
			free(color);
		}
		else
		{
			intensity += compute_special_lights(l_vectors, light, scene, objects);
			//color = multiply_vectors(ambient_intensity / scene->total_intensity, *actual_color);
			light_color = color_to_rgb(light->color);
			new_color = new_vector(((light_color->x * (intensity / scene->total_intensity)) - obj_color->x)
			,((light_color->y * (intensity / scene->total_intensity)) -  obj_color->y)
			,((light_color->z * (intensity / scene->total_intensity)) - obj_color->z));
			//printf("color: (%f, %f, %f)\n", new_color->x / 255, new_color->y / 255, new_color->z / 255);
			color = new_vector(actual_color->x + (obj_color->x + (new_color->x)),
		actual_color->y + (obj_color->y + (new_color->y)),
		actual_color->z + (obj_color->z + (new_color->z)));
			free(new_color);
			free(light_color);
			//printf("new_color (%f, %f, %f)\n", color->x, color->y, color->z);
			//free(actual_color);
			//free(new_color);
			//actual_color = new_vector(color->x, color->y, color->z);
			//free(color);
			//printf("color: (%f, %f, %f)\n", color->x, color->y, color->z);
			rearrange_rgb(color);
			actual_color = new_vector(color->x, color->y, color->z);
			free(color);
		}
		lights = lights->next;
		//printf("actual_color (%f, %f, %f)\n", actual_color->x, actual_color->y, actual_color->z);
	}
	//printf("end actual_color (%f, %f, %f)\n", actual_color->x, actual_color->y, actual_color->z);
	//printf("intensity : %f\n", intensity);
	return (rgb_to_color(actual_color));
}
