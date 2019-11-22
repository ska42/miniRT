/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:09:23 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 06:14:34 by lmartin          ###   ########.fr       */
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
	float		calcul_c;
	float		reflective;
	s_vector	*difference;
	s_vector	*center;
	s_vector	*prev_origin;
}				s_sphere;

s_sphere		*new_sphere(float radius, int color, float shiny, s_vector *center);
void			free_sphere(s_sphere *sphere);
s_sphere		*cpy_sphere(s_sphere *sphere);

#endif
