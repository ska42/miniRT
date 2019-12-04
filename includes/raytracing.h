/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:47:59 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:07 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "minirt.h"
# include "scene.h"

/*
** Intersect
*/
float		intersect_sphere(t_vector origin, t_vector direction,
t_sphere *object);
float		intersect_plan(t_vector origin, t_vector direction,
t_plan *object);

/*
** Raytracing
*/
int			trace_ray(t_vector direction, t_scene *scene);
float		closest_intersection(t_vector origin, t_vector direction,
t_scene *scene, t_lstobjects **closest_object);
int			setup_l_vectors_and_calculate(t_lstobjects *closest_object,
t_vector direction, float closest_t, t_scene *scene);

#endif
