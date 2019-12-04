/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 06:43:09 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:18:23 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "scene.h"
#include "camera.h"
#include "lstobjects.h"

t_scene		*new_empty_scene(int color)
{
	t_scene	*scene;

	if (!(scene = malloc(sizeof(t_scene))))
		print_error_and_exit(-7);
	scene->viewport = NULL;
	scene->viewplane = NULL;
	scene->cameras = NULL;
	scene->objects = NULL;
	scene->lights = NULL;
	scene->total_intensity = 0;
	scene->background_color = color;
	scene->t_min = 0.001;
	scene->t_max = -1;
	scene->depth = 2;
	return (scene);
}

t_scene		*new_scene(t_lstobjects *cameras, t_lstobjects *objects,
t_lstobjects *lights, int color)
{
	t_scene	*scene;

	if (!(scene = malloc(sizeof(t_scene))))
		print_error_and_exit(-7);
	scene->viewport = NULL;
	scene->viewplane = NULL;
	scene->cameras = cameras;
	scene->objects = objects;
	scene->lights = lights;
	scene->background_color = color;
	scene->total_intensity = 0;
	scene->t_min = 0.001;
	scene->t_max = -1;
	scene->depth = 2;
	return (scene);
}
