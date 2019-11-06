/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:05:15 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 14:38:57 by lmartin          ###   ########.fr       */
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
	int			color;
	float		shiny;
	float		reflective;
}				s_triangle;

s_triangle	*new_triangle(s_vector* a, s_vector *b, s_vector *c, int color);

#endif
