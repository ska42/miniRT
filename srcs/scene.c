/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 06:43:09 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 01:58:02 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

s_scene		*new_scene(s_vector *origin, s_lstobjects *objects,
s_lstobjects *lights, int color)
{
	s_scene	*scene;

	scene = malloc(sizeof(s_scene));
	scene->origin = origin;
	scene->objects = objects;
	scene->lights = lights;
	scene->background_color = color;
	scene->t_min = 1;
	scene->t_max = -1;
	scene->depth = 3;
	return (scene);
}

s_scene		*cpy_scene(s_scene *scene)
{
	s_scene *new;

	new = malloc(sizeof(s_scene));
	new->origin = scene->origin;
	new->objects = scene->objects;
	new->lights = scene->lights;
	new->background_color = scene->background_color;
	new->t_min = scene->t_min;
	new->t_max = scene->t_max;
	new->depth = scene->depth;
	return (new);
}
