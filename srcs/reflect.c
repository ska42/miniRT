/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 02:37:46 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 02:50:30 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_vector	*reflect_ray(s_vector v1, s_vector v2)
{
	s_vector *v_temp;
	s_vector *new;

	v_temp = multiply_vectors(2 * product_vectors(v1, v2), v2);
	new = subtract_vectors(*v_temp, v1);
	free(v_temp);
	return (new);
}

int			color_with_reflect(s_lstobjects *closest_object, s_scene *scene,
s_lightning_vectors *l_vectors, int color)
{
	s_vector				*temp;
	s_vector				*temp2;
	s_vector				*reflect_color;

	printf("reflect\n");
	temp = reflect_ray(*(l_vectors->view), *(l_vectors->normal));
	temp2 = color_to_rgb(color);
	scene->origin = l_vectors->point;
	scene->depth--;
	color = trace_ray(*temp, scene);
	free(temp);
	if (closest_object->type == TYPE_SPHERE)
		temp = multiply_vectors(1 - ((s_sphere *)closest_object)->reflective,
*temp2);
	free(temp2);
	reflect_color = color_to_rgb(color);
	if (closest_object->type == TYPE_SPHERE)
		temp2 = multiply_vectors(
((s_sphere *)closest_object->object)->reflective, *reflect_color);
	free(reflect_color);
	reflect_color = add_vectors(*temp, *temp2);
	free(temp);
	free(temp2);
	rearrange_rgb(reflect_color);
	color = rgb_to_color(reflect_color);
	free(reflect_color);
	printf("reflect_end\n");
	return (color);
}
