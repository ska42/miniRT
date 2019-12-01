/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 00:59:45 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/01 01:02:28 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		*cpy_object_choice(s_lstobjects *objects)
{
	void			*object;

	if (objects->type == TYPE_SPHERE)
		object = cpy_sphere(objects->object);
	if (objects->type == TYPE_PLAN)
		object = cpy_plan(objects->object);
	if (objects->type == TYPE_SQUARE)
		object = cpy_square(objects->object);
	if (objects->type == TYPE_TRIANGLE)
		object = cpy_triangle(objects->object);
	if (objects->type == TYPE_CYLINDER)
		object = cpy_cylinder(objects->object);
	return (object);
}

void		cpy_cameras_and_objects(s_scene **new, s_scene *scene)
{
	int				i;
	s_lstobjects	*cameras;
	s_lstobjects	*objects;

	cameras = scene->cameras;
	(*new)->cameras = NULL;
	i = -1;
	cameras = cameras->prev;
	while (++i < scene->nb_camera && (cameras = cameras->next))
		add_back(&((*new)->cameras), TYPE_CAMERA,
cpy_camera(((s_camera *)cameras->object)), -1);
	objects = scene->objects;
	(*new)->objects = NULL;
	while (objects)
	{
		add_back(&((*new)->objects), objects->type,
cpy_object_choice(objects), objects->reflective);
		objects = objects->next;
	}
}

s_scene		*cpy_scene(s_scene *scene)
{
	s_scene			*new;

	if (!(new = malloc(sizeof(s_scene))))
		print_error_and_exit(-7);
	new->viewport = scene->viewport;
	new->viewplane = scene->viewplane;
	new->lights = scene->lights;
	cpy_cameras_and_objects(&new, scene);
	new->total_intensity = scene->total_intensity;
	new->background_color = scene->background_color;
	new->t_min = scene->t_min;
	new->t_max = scene->t_max;
	new->depth = scene->depth;
	return (new);
}

void		free_cpy_scene_choice(s_scene *scene)
{
	if (scene->objects->type == TYPE_SPHERE)
		free_sphere((s_sphere *)scene->objects->object);
	if (scene->objects->type == TYPE_PLAN)
		free_plan((s_plan *)scene->objects->object);
	if (scene->objects->type == TYPE_SQUARE)
		free_square((s_square *)scene->objects->object);
	if (scene->objects->type == TYPE_TRIANGLE)
		free_triangle((s_triangle *)scene->objects->object);
	if (scene->objects->type == TYPE_CYLINDER)
		free_cylinder((s_cylinder *)scene->objects->object);
}

int			free_cpy_scene(s_scene *scene)
{
	int				i;
	s_lstobjects	*cameras;
	s_lstobjects	*objects;

	i = -1;
	while (++i < scene->nb_camera)
	{
		cameras = scene->cameras->next;
		free(scene->cameras);
		scene->cameras = cameras;
	}
	objects = scene->objects;
	while (objects)
	{
		objects = objects->next;
		free_cpy_scene_choice(scene);
		free(scene->objects);
		scene->objects = objects;
	}
	free(scene);
	return (0);
}
