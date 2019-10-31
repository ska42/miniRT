/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:47:59 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/31 17:39:33 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

float	compute_lightning(s_vector *point, s_vector *normal, s_lstobjects *lights);
float	intersect_sphere(s_vector origin, s_vector direction, s_sphere *object);
int		trace_ray(s_vector origin, s_vector direction, s_lstobjects *objects, float t_min_max[2], s_lstobjects *lights);

#endif
