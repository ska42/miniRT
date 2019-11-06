/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:29:56 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 03:35:27 by lmartin          ###   ########.fr       */
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
s_light *light, s_scene *scene)
{
	float			intensity;
	float			n_dot_l;
	float			length_v;
	s_vector		*vec_l;
	s_lstobjects	*shadow_obj;

	intensity = 0;
	length_v = length_vectors(*l_vectors->view);
	vec_l = type_light(l_vectors, light, scene);
	closest_intersection(*l_vectors->point, *vec_l, scene, &shadow_obj);
	if (shadow_obj)
		return (intensity);
	n_dot_l = product_vectors(*l_vectors->normal, *vec_l);
	if (n_dot_l > 0)
		intensity += (light->intensity * n_dot_l) /
((length_vectors(*l_vectors->normal) * length_vectors(*vec_l)));
	if (l_vectors->shiny != -1)
		intensity += calcul_shiny(l_vectors, light, length_v, vec_l);
	if (light->type == TYPE_POINT)
		free(vec_l);
	return (intensity);
}

float	compute_lightning(s_lightning_vectors *l_vectors,
s_lstobjects *lights, s_scene *scene)
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
			intensity += compute_special_lights(l_vectors, light, scene);
		lights = lights->next;
	}
	return (intensity);
}
