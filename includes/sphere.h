/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:09:23 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/03 23:11:50 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPHERE_H
# define SPHERE_H

# include <stdlib.h>
# include "vector.h"

typedef struct 	t_sphere
{
	float		radius;
	int			color;
	float		shiny;
	float		reflective;
	s_vector	*center;
}				s_sphere;

s_sphere		*new_sphere(float radius, int color,
float shiny, s_vector *center);
s_sphere		*new_default_sphere(float radius, int color);
void 			set_shiny(s_sphere *sphere, float shiny);

#endif
