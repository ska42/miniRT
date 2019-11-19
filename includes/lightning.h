/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:30:36 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/19 02:11:16 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTNING_H
# define LIGHTNING_H

#include <stdlib.h>
#include "lstobjects.h"
#include "scene.h"
#include "vector.h"
#include "light.h"

float		calcul_shiny(s_lightning_vectors *l_vectors, s_light *light, float length_v, s_vector *vec_l);
float		compute_special_lights(s_lightning_vectors *l_vectors, s_light *light, s_scene *scene, s_lstobjects *objects);
s_vector	*type_light(s_lightning_vectors *l_vectors, s_light *light, s_scene *scene);
float		compute_lightning(s_lightning_vectors *l_vectors, s_lstobjects *lights, s_scene *scene, s_lstobjects *objects);

#endif
