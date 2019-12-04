/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:18:09 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 13:07:07 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "square.h"
# include "plan.h"
# include "sphere.h"
# include "triangle.h"
# include "vector.h"

void		init_cylinder_intersect_cylinder(s_vector origin, s_cylinder *object);
float		intersect_global(s_vector origin, s_vector direction, s_lstobjects *objects);
float		intersect_sphere(s_vector origin, s_vector direction, s_sphere *object);
float		intersect_plan(s_vector origin, s_vector direction, s_plan *object);
float		intersect_square(s_vector origin, s_vector direction, s_square *object);
float		intersect_triangle(s_vector origin, s_vector direction, s_triangle *object);
float		intersect_cylinder(s_vector origin, s_vector direction, s_cylinder *object);

#endif
