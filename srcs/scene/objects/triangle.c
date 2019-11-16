/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:32:43 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 14:45:08 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_triangle	*new_triangle(s_vector* a, s_vector *b, s_vector *c, int color)
{
	s_triangle *triangle;

	triangle = malloc(sizeof(s_triangle));
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	triangle->color = color;
	triangle->shiny = -1;
	triangle->reflective = -1;
	return (triangle);
}
