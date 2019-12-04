/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 00:59:45 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:19:25 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		*cpy_object_choice(t_lstobjects *objects)
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

void		cpy_cameras_and_objects(t_scene **new, t_scene *scene)
{
	int				i;
	t_lstobjects	*cameras;
	t_lstobjects	*objects;

	cameras = scene->cameras;
	(*new)->cameras = NULL;
	i = -1;
	cameras = cameras->prev;
	while (++i < scene->nb_camera && (cameras = cameras->next))
		add_back(&((*new)->cameras), TYPE_CAMERA,
cpy_camera(((t_camera *)cameras->object)), -1);
	objects = scene->objects;
	(*new)->objects = NULL;
	while (objects)
	{
		add_back(&((*new)->objects), objects->type,
cpy_object_choice(objects), objects->reflective);
		objects = objects->next;
	}
}

t_scene		*cpy_scene(t_scene *scene)
{
	t_scene			*new;

	if (!(new = malloc(sizeof(t_scene))))
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

void		free_cpy_scene_choice(t_scene *scene)
{
	if (scene->objects->type == TYPE_SPHERE)
		free_sphere((t_sphere *)scene->objects->object);
	if (scene->objects->type == TYPE_PLAN)
		free_plan((t_plan *)scene->objects->object);
	if (scene->objects->type == TYPE_SQUARE)
		free_square((t_square *)scene->objects->object);
	if (scene->objects->type == TYPE_TRIANGLE)
		free_triangle((t_triangle *)scene->objects->object);
	if (scene->objects->type == TYPE_CYLINDER)
		free_cylinder((t_cylinder *)scene->objects->object);
}

int			free_cpy_scene(t_scene *scene)
{
	int				i;
	t_lstobjects	*cameras;
	t_lstobjects	*objects;

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
