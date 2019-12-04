/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:18:09 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:16 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "square.h"
# include "plan.h"
# include "sphere.h"
# include "triangle.h"
# include "vector.h"

void		init_cylinder_intersect_cylinder(t_vector origin,
t_cylinder *object);
float		intersect_global(t_vector origin, t_vector direction,
t_lstobjects *objects);
float		intersect_sphere(t_vector origin, t_vector direction,
t_sphere *object);
float		intersect_plan(t_vector origin, t_vector direction,
t_plan *object);
float		intersect_square(t_vector origin, t_vector direction,
t_square *object);
float		intersect_triangle(t_vector origin, t_vector direction,
t_triangle *object);
float		intersect_cylinder(t_vector origin, t_vector direction,
t_cylinder *object);

#endif
