/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 06:43:09 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/02 07:19:27 by lmartin          ###   ########.fr       */
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
	return (scene);
}
