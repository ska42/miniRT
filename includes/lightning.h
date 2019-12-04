/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:30:36 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:32:27 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTNING_H
# define LIGHTNING_H

# include <stdlib.h>
# include "lstobjects.h"
# include "scene.h"
# include "vector.h"
# include "light.h"

typedef	struct			s_l_o_v_s
{
	t_lightning_vectors *l_vectors;
	t_scene				*scene;
	t_vector			*color[4];
}						t_l_o_v_s;

typedef	struct			s_scene_direction
{
	t_scene				*scene;
	t_vector			*direction;
}						t_scene_direction;

float					calcul_shiny(t_lightning_vectors *l_vectors,
t_light *light, float length_v, t_vector *vec_l);
float					compute_special_lights(t_lightning_vectors *l_vectors,
t_light *light, t_scene *scene, t_lstobjects *objects);
t_vector				*type_light(t_lightning_vectors *l_vectors,
t_light *light, t_scene *scene);
void					calculate_normal(t_lightning_vectors *l_vectors,
t_light *light, t_scene *scene, t_lstobjects *objects);
t_vector				*set_shiny_and_get_color(t_lightning_vectors *l_vectors,
t_lstobjects *objects);
int						compute_lightning(t_lightning_vectors *l_vectors,
t_lstobjects *lights, t_scene *scene, t_lstobjects *objects);
void					set_color_special_lights(float *intensity,
t_l_o_v_s *lovs, t_lstobjects *objects, t_lstobjects *lights);
void					set_color_ambient(t_vector *color[4],
float *intensity, t_lstobjects *lights);
void					check_light_intersect_sphere(
t_lightning_vectors *l_vectors, void *object);
void					check_light_intersect_plan(
t_lightning_vectors *l_vectors, void *object, t_light *light);
void					check_light_triangle(
t_lightning_vectors *l_vectors, void *object, t_light *light);
void					check_light_square(
t_lightning_vectors *l_vectors, void *object, t_light *light);
void					check(t_lightning_vectors *l_vectors, void *object,
t_light *light);
void					check_face(t_lightning_vectors *l_vectors, void *object,
t_scene_direction *s_d, t_light *light);
void					check_ext(t_lightning_vectors *l_vectors, void *object,
t_scene_direction *s_d, t_light *light);
void					check_light_intersect_cylinder(
t_lightning_vectors *l_vectors, void *object, t_scene_direction *s_d,
t_light *light);
float					calcul_shiny(t_lightning_vectors *l_vectors,
t_light *light, float length_v, t_vector *vec_l);
t_vector				*set_shiny_and_get_color(t_lightning_vectors *l_vectors,
t_lstobjects *objects);

#endif
