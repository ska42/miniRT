/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:47:59 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/23 22:31:23 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "miniRT.h"
# include "scene.h"

/** INTERSECT **/
float		intersect_sphere(s_vector origin, s_vector direction, s_sphere *object);
float		intersect_plan(s_vector origin, s_vector direction, s_plan *object);

/** RAYTRACING **/
int			trace_ray(s_vector direction, s_scene *scene);
float		closest_intersection(s_vector origin, s_vector direction, s_scene *scene, s_lstobjects **closest_object);
int			setup_l_vectors_and_calculate(s_lstobjects *closest_object, s_vector direction, float closest_t, s_scene *scene);

#endif
