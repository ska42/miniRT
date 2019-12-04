/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiny.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:44:37 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 17:16:32 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		calcul_shiny(t_lightning_vectors *l_vectors, t_light *light,
float length_v, t_vector *vec_l)
{
	float		r_dot_v;
	t_vector	*vec_r;
	t_vector	*temp;
	float		intensity;

	intensity = 0;
	temp = multiply_vectors(2.0 * product_vectors(*l_vectors->normal,
*vec_l), *l_vectors->normal);
	vec_r = subtract_vectors(*temp, *vec_l);
	free(temp);
	r_dot_v = product_vectors(*vec_r, *l_vectors->view);
	if (r_dot_v > 0)
		intensity += light->intensity * pow(r_dot_v / (length_vectors(*vec_r) *
length_v), l_vectors->shiny);
	free(vec_r);
	return (intensity);
}

t_vector	*set_shiny_and_get_color(t_lightning_vectors *l_vectors,
t_lstobjects *objects)
{
	if (objects->type == TYPE_SPHERE)
	{
		l_vectors->shiny = ((t_sphere *)objects->object)->shiny;
		return (((t_sphere *)objects->object)->color);
	}
	else if (objects->type == TYPE_PLAN)
	{
		l_vectors->shiny = ((t_plan *)objects->object)->shiny;
		return (((t_plan *)objects->object)->color);
	}
	l_vectors->shiny = -1;
	if (objects->type == TYPE_SQUARE)
		return (((t_square *)objects->object)->color);
	else if (objects->type == TYPE_TRIANGLE)
		return (((t_triangle *)objects->object)->color);
	else if (objects->type == TYPE_CYLINDER)
		return (((t_cylinder *)objects->object)->color);
	return (NULL);
}
