/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:43:07 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:20:10 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check(t_lightning_vectors *l_vectors, void *object, t_light *light)
{
	float			denom;
	float			k[4];
	float			t;
	t_vector		*temp[2];
	t_vector		*point;

	temp[0] = multiply_vectors(-1, *((t_plan *)object)->normal);
	denom = -(product_vectors(*((t_plan *)object)->normal, *(
(t_plan *)object)->point));
	k[0] = product_vectors(*light->vector, *((t_plan *)object)->normal) + denom;
	k[1] = product_vectors(*temp[0], *((t_plan *)object)->normal);
	t = -(k[0] / k[1]);
	temp[1] = multiply_vectors(t, *temp[0]);
	free(temp[0]);
	point = add_vectors(*light->vector, *temp[1]);
	free(temp[1]);
	temp[1] = subtract_vectors(*light->vector, *point);
	l_vectors->normal = multiply_vectors(1 /
length_vectors(*temp[1]), *temp[1]);
	free(temp[1]);
	free(point);
}

void	check_face(t_lightning_vectors *l_vectors, void *object,
t_scene_direction *s_d, t_light *light)
{
	float		k[4];
	t_vector	*temp;
	t_vector	*point;
	t_scene		*scene;
	t_vector	direction;

	scene = s_d->scene;
	direction = *(s_d->direction);
	k[0] = product_vectors(*((t_camera *)scene->cameras->object)->origin,
*((t_cylinder *)object)->orientation) - (product_vectors(*(
(t_cylinder *)object)->orientation, *((t_cylinder *)object)->point1));
	k[1] = product_vectors(direction, *((t_cylinder *)object)->orientation);
	k[2] = -(k[0] / k[1]);
	if (k[2] > 0)
	{
		temp = multiply_vectors(k[2], direction);
		point = add_vectors(*((t_camera *)scene->cameras->object)->origin
, *temp);
		free(temp);
		k[0] = distance_points(*point, *((t_cylinder *)object)->point1);
		free(point);
		if (k[0] < ((t_cylinder *)object)->diameter / 2)
			check(l_vectors, object, light);
	}
}

void	check_ext(t_lightning_vectors *l_vectors, void *object,
t_scene_direction *s_d, t_light *light)
{
	t_vector		*temp[2];
	float			denom;
	float			k[4];
	t_scene			*scene;
	t_vector		direction;

	scene = s_d->scene;
	direction = *(s_d->direction);
	denom = -(product_vectors(*((t_cylinder *)object)->orientation, *(
(t_cylinder *)object)->point2));
	k[0] = product_vectors(*((t_camera *)scene->cameras->object)->origin, *(
(t_cylinder *)object)->orientation) + denom;
	k[1] = product_vectors(direction, *((t_cylinder *)object)->orientation);
	k[2] = -(k[0] / k[1]);
	if (k[2] > 0)
	{
		temp[0] = multiply_vectors(k[2], direction);
		temp[1] = add_vectors(*((t_camera *)scene->cameras->object)->origin
, *temp[0]);
		free(temp[0]);
		k[0] = distance_points(*temp[1], *((t_cylinder *)object)->point2);
		free(temp[1]);
		if (k[0] < ((t_cylinder *)object)->diameter / 2)
			check(l_vectors, object, light);
	}
}

void	check_light_intersect_cylinder(t_lightning_vectors *l_vectors,
void *object, t_scene_direction *s_d, t_light *light)
{
	t_vector		*temp;
	t_vector		*temp2;
	t_scene			*scene;
	t_vector		direction;

	scene = s_d->scene;
	direction = *(s_d->direction);
	temp2 = NULL;
	temp = subtract_vectors(*l_vectors->point, *(
((t_cylinder *)object)->center));
	l_vectors->normal = multiply_vectors(1 / length_vectors(*temp), *temp);
	free(temp);
	if (product_vectors(*((t_cylinder *)object)->orientation, direction) < 0)
	{
		check_face(l_vectors, object, s_d, light);
	}
	else if (product_vectors(*((t_cylinder *)object)->orientation,
direction) > 0)
	{
		check_ext(l_vectors, object, s_d, light);
	}
	free(temp2);
}
