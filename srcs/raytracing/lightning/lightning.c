/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:29:56 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:55:14 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*type_light(t_lightning_vectors *l_vectors,
t_light *light, t_scene *scene)
{
	t_vector *vec_l;

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

void		calculate_normal(t_lightning_vectors *l_vectors,
t_light *light, t_scene *scene, t_lstobjects *objects)
{
	void					*object;
	t_vector				direction;
	t_scene_direction		*s_d;

	object = objects->object;
	direction = *multiply_vectors(-1, *l_vectors->view);
	free(l_vectors->normal);
	s_d = malloc(sizeof(t_scene_direction));
	s_d->scene = scene;
	s_d->direction = &direction;
	if (objects->type == TYPE_SPHERE)
		check_light_intersect_sphere(l_vectors, object);
	else if (objects->type == TYPE_CYLINDER)
		check_light_intersect_cylinder(l_vectors, object, s_d, light);
	else if (objects->type == TYPE_PLAN)
		check_light_intersect_plan(l_vectors, object, light);
	else if (objects->type == TYPE_TRIANGLE)
		check_light_triangle(l_vectors, object, light);
	else if (objects->type == TYPE_SQUARE)
		check_light_square(l_vectors, object, light);
}

float		compute_special_lights(t_lightning_vectors *l_vectors,
t_light *light, t_scene *scene, t_lstobjects *objects)
{
	float			i_n_dot_l[2];
	t_vector		*vec_l;
	t_lstobjects	*shadow_obj;
	t_vector		direction;

	i_n_dot_l[0] = 0;
	vec_l = type_light(l_vectors, light, scene);
	direction = *multiply_vectors(-1, *l_vectors->view);
	closest_intersection(*l_vectors->point, *vec_l, scene, &shadow_obj);
	if (!shadow_obj)
	{
		calculate_normal(l_vectors, light, scene, objects);
		i_n_dot_l[1] = product_vectors(*l_vectors->normal, *vec_l);
		if (i_n_dot_l[1] > 0)
		{
			i_n_dot_l[0] += ((light->intensity * i_n_dot_l[1]) /
		((length_vectors(*l_vectors->normal) * length_vectors(*vec_l))));
		}
		if (l_vectors->shiny != -1)
			i_n_dot_l[0] += calcul_shiny(l_vectors, light,
length_vectors(*l_vectors->view), vec_l);
	}
	if (light->type == TYPE_POINT)
		free(vec_l);
	return (i_n_dot_l[0]);
}

int			compute_lightning(t_lightning_vectors *l_vectors,
t_lstobjects *lights, t_scene *scene, t_lstobjects *objects)
{
	float		intensity;
	int			ret_color;
	t_l_o_v_s	*lovs;

	if (!(lovs = malloc(sizeof(t_l_o_v_s))))
		print_error_and_exit(-7);
	lovs->l_vectors = l_vectors;
	lovs->scene = scene;
	lovs->color[3] = set_shiny_and_get_color(l_vectors, objects);
	lovs->color[2] = new_vector(0, 0, 0);
	while (lights)
	{
		intensity = 0;
		if (((t_light *)lights->object)->type == TYPE_AMBIENT)
			set_color_ambient(lovs->color, &intensity, lights);
		else
			set_color_special_lights(&intensity, lovs, objects, lights);
		lovs->color[2] = cpy_vector(lovs->color[0]);
		free(lovs->color[0]);
		lights = lights->next;
	}
	free(lovs);
	ret_color = rgb_to_color(lovs->color[2]);
	free(lovs->color[2]);
	return (ret_color);
}
