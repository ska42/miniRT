/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:18:09 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 14:49:44 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "square.h"
# include "plan.h"
# include "sphere.h"
# include "triangle.h"
# include "vector.h"

float		intersect_sphere(s_vector origin, s_vector direction, s_sphere *object);
float		intersect_plan(s_vector origin, s_vector direction, s_plan *object);
float		intersect_square(s_vector origin, s_vector direction, s_square *object);
float		intersect_triangle(s_vector origin, s_vector direction, s_triangle *object);

#endif
