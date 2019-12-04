/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:32:43 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:19:47 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "miniRT.h"

t_triangle	*new_triangle(t_vector *a, t_vector *b, t_vector *c,
t_vector *color)
{
	t_triangle *triangle;

	if (!(triangle = malloc(sizeof(t_triangle))))
		print_error_and_exit(-7);
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	triangle->u = subtract_vectors(*triangle->b, *triangle->a);
	triangle->v = subtract_vectors(*triangle->c, *triangle->a);
	triangle->normal = cross(*triangle->u, *triangle->v);
	triangle->dot_uu = product_vectors(*triangle->u, *triangle->u);
	triangle->dot_uv = product_vectors(*triangle->u, *triangle->v);
	triangle->dot_vv = product_vectors(*triangle->v, *triangle->v);
	triangle->color = color;
	triangle->shiny = -1;
	triangle->calcul_a = 0;
	triangle->calcul_d =
triangle->dot_uv * triangle->dot_uv - triangle->dot_uu * triangle->dot_vv;
	triangle->prev_origin = NULL;
	return (triangle);
}

void		free_triangle(t_triangle *triangle)
{
	free(triangle->color);
	free(triangle->a);
	free(triangle->b);
	free(triangle->c);
	free(triangle->u);
	free(triangle->v);
	free(triangle->normal);
	if (triangle->prev_origin)
		free(triangle->prev_origin);
	free(triangle);
}

t_triangle	*cpy_triangle(t_triangle *triangle)
{
	t_triangle *new;

	if (!(new = malloc(sizeof(t_triangle))))
		print_error_and_exit(-7);
	new->a = cpy_vector(triangle->a);
	new->b = cpy_vector(triangle->b);
	new->c = cpy_vector(triangle->c);
	new->u = cpy_vector(triangle->u);
	new->v = cpy_vector(triangle->v);
	new->normal = cpy_vector(triangle->normal);
	new->color = cpy_vector(triangle->color);
	new->dot_uu = triangle->dot_uu;
	new->dot_uv = triangle->dot_uv;
	new->dot_vv = triangle->dot_vv;
	new->shiny = triangle->shiny;
	new->calcul_a = 0;
	new->calcul_d = triangle->calcul_d;
	new->prev_origin = NULL;
	return (new);
}
