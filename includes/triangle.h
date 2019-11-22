/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:05:15 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 05:48:17 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include <stdlib.h>
# include "vector.h"

typedef struct	t_triangle
{
	s_vector	*a;
	s_vector	*b;
	s_vector	*c;
	s_vector	*u;
	s_vector	*v;
	s_vector	*normal;
	int			color;
	float		shiny;
	float		reflective;
	float		calcul_a;
	float		dot_uu;
	float		dot_uv;
	float		dot_vv;
	float		calcul_d;
	s_vector	*prev_origin;
}				s_triangle;

s_triangle	*new_triangle(s_vector* a, s_vector *b, s_vector *c, int color);
void		free_triangle(s_triangle *triangle);
s_triangle	*cpy_triangle(s_triangle *triangle);

#endif
