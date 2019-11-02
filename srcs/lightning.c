/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:29:56 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/02 09:30:05 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	calcul_reflection(s_lightning_vectors *l_vectors, s_light *light,
float length_v, s_vector *vec_l)
{
	float		r_dot_v;
	s_vector	*vec_r;
	s_vector	*temp;
	float		intensity;

	intensity = 0;
	temp = multiply_vectors(2.0 * product_vectors(*l_vectors->normal, *vec_l), *l_vectors->normal);
	vec_r = subtract_vectors(*temp, *vec_l);
	free(temp);
	r_dot_v = product_vectors(*vec_r, *l_vectors->view);
	if (r_dot_v > 0)
		intensity += light->intensity * pow(r_dot_v / (length_vectors(*vec_r) * length_v), l_vectors->reflection);
	free(vec_r);
	return (intensity);
}

float	compute_special_lights(s_lightning_vectors *l_vectors, s_light *light)
{
	float		intensity;
	float		n_dot_l;
	float		length_v;
	s_vector	*vec_l;

	intensity = 0;
	length_v = length_vectors(*l_vectors->view);
	vec_l = NULL;
	if (light->type == TYPE_POINT)
		vec_l = subtract_vectors(*light->vector, *l_vectors->point);
	else if (light->type == TYPE_DIRECTIONAL)
		vec_l = light->vector;
	n_dot_l = product_vectors(*l_vectors->normal, *vec_l);
	if (n_dot_l > 0)
		intensity += light->intensity * n_dot_l /
(length_vectors(*l_vectors->normal) * length_vectors(*vec_l));
	if (l_vectors->reflection != -1)
		intensity += calcul_reflection(l_vectors, light, length_v, vec_l);
	if (light->type == TYPE_POINT)
		free(vec_l);
	return (intensity);
}

float	compute_lightning(s_lightning_vectors *l_vectors, s_lstobjects *lights)
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
			intensity += compute_special_lights(l_vectors, light);
		lights = lights->next;
	}
	return (intensity);
}
