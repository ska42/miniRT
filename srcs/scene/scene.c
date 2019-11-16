/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 06:43:09 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 03:22:46 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

s_scene		*new_empty_scene(int color)
{
	s_scene	*scene;

	scene = malloc(sizeof(s_scene));
	scene->viewport = NULL;
	scene->viewplane = NULL;
	scene->cameras = NULL;
	scene->objects = NULL;
	scene->lights = NULL;
	scene->background_color = color;
	scene->t_min = 0.001;
	scene->t_max = -1;
	scene->depth = 3;
	return (scene);
}

s_scene		*new_scene(s_lstobjects* cameras, s_lstobjects *objects,
s_lstobjects *lights, int color)
{
	s_scene	*scene;

	scene = malloc(sizeof(s_scene));
	scene->viewport = NULL;
	scene->viewplane = NULL;
	scene->cameras = cameras;
	scene->objects = objects;
	scene->lights = lights;
	scene->background_color = color;
	scene->t_min = 0.001;
	scene->t_max = -1;
	scene->depth = 3;
	return (scene);
}

s_scene		*cpy_scene(s_scene *scene)
{
	s_scene *new;

	new = malloc(sizeof(s_scene));
	new->viewport = scene->viewport;
	new->viewplane = scene->viewplane;
	new->cameras = scene->cameras;
	new->objects = scene->objects;
	new->lights = scene->lights;
	new->background_color = scene->background_color;
	new->t_min = scene->t_min;
	new->t_max = scene->t_max;
	new->depth = scene->depth;
	return (new);
}
