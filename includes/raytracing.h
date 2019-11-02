/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:47:59 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/02 07:38:16 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "miniRT.h"
# include "scene.h"

float	compute_lightning(s_lightning_vectors *l_vectors, s_lstobjects *lights);
float	intersect_sphere(s_vector origin, s_vector direction, s_sphere *object);
int		trace_ray(s_vector direction, s_scene *scene);
int		calculate_new_color(s_lstobjects *objects, s_lstobjects *lights, s_lightning_vectors *l_vectors);

#endif
