/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:47:59 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/03 10:06:25 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "miniRT.h"
# include "scene.h"

float	intersect_sphere(s_vector origin, s_vector direction, s_sphere *object);
int		trace_ray(s_vector direction, s_scene *scene);
int		calculate_new_color(s_lstobjects *objects, s_lstobjects *lights, s_lightning_vectors *l_vectors, s_scene *scene);
float	closest_intersection(s_vector origin, s_vector direction, s_scene *scene, s_lstobjects **closest_object);
int		setup_l_vectors_and_calculate(s_lstobjects *closest_object, s_vector direction, float closest_t, s_scene *scene);

#endif
