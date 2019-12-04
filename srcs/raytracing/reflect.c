/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 02:37:46 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:55 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*reflect_ray(t_vector v1, t_vector v2)
{
	t_vector *v_temp;
	t_vector *new;

	v_temp = multiply_vectors(2 * product_vectors(v1, v2), v2);
	new = subtract_vectors(*v_temp, v1);
	free(v_temp);
	return (new);
}

int			color_with_reflect(t_lstobjects *closest_object, t_scene *scene,
t_lightning_vectors *l_vectors, int color)
{
	t_vector				*temp;
	t_vector				*temp2;
	t_vector				*reflect_color;

	temp = reflect_ray(*(l_vectors->view), *(l_vectors->normal));
	temp2 = color_to_rgb(color);
	((t_camera *)scene->cameras->object)->origin = l_vectors->point;
	scene->depth--;
	color = trace_ray(*temp, scene);
	free(temp);
	temp = multiply_vectors(1 - closest_object->reflective, *temp2);
	free(temp2);
	reflect_color = color_to_rgb(color);
	temp2 = multiply_vectors(closest_object->reflective, *reflect_color);
	free(reflect_color);
	reflect_color = add_vectors(*temp, *temp2);
	free(temp);
	free(temp2);
	rearrange_rgb(reflect_color);
	color = rgb_to_color(reflect_color);
	free(reflect_color);
	return (color);
}
