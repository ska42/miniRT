/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 05:10:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/01 00:34:17 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "miniRT.h"

void		place_points(s_square **new)
{
	s_vector	*vector[4];

	vector[0] = new_vector((*new)->size / 2, (*new)->size / 2, 0);
	vector[1] = new_vector(-(*new)->size / 2, (*new)->size / 2, 0);
	vector[2] = new_vector((*new)->size / 2, -(*new)->size / 2, 0);
	vector[3] = new_vector(-(*new)->size / 2, -(*new)->size / 2, 0);
	rot(vector[0], (*new)->orientation);
	rot(vector[1], (*new)->orientation);
	rot(vector[2], (*new)->orientation);
	rot(vector[3], (*new)->orientation);
	(*new)->a = add_vectors(*vector[0], *(*new)->center);
	(*new)->b = add_vectors(*vector[1], *(*new)->center);
	(*new)->c = add_vectors(*vector[2], *(*new)->center);
	(*new)->d = add_vectors(*vector[3], *(*new)->center);
}

s_square	*new_square(s_vector *center, s_vector *orientation, float size,
s_vector *color)
{
	s_square	*new;

	if (!(new = malloc(sizeof(s_square))))
		print_error_and_exit(-7);
	new->center = center;
	new->orientation = orientation;
	new->size = size;
	new->color = color;
	place_points(&new);
	new->ab = subtract_vectors(*new->b, *new->a);
	new->ac = subtract_vectors(*new->c, *new->a);
	new->normal = cross(*new->ab, *new->ac);
	new->shiny = -1;
	new->calcul_a = 0;
	new->prev_origin = NULL;
	return (new);
}

void		free_square(s_square *square)
{
	free(square->center);
	free(square->orientation);
	free(square->color);
	free(square->a);
	free(square->b);
	free(square->c);
	free(square->d);
	free(square->ab);
	free(square->ac);
	free(square->normal);
	if (square->prev_origin)
		free(square->prev_origin);
	free(square);
}

s_square	*cpy_square(s_square *square)
{
	s_square *new;

	if (!(new = malloc(sizeof(s_square))))
		print_error_and_exit(-7);
	new->center = cpy_vector(square->center);
	new->orientation = cpy_vector(square->orientation);
	new->a = cpy_vector(square->a);
	new->b = cpy_vector(square->b);
	new->c = cpy_vector(square->c);
	new->d = cpy_vector(square->d);
	new->ab = cpy_vector(square->ab);
	new->ac = cpy_vector(square->ac);
	new->normal = cpy_vector(square->normal);
	new->color = cpy_vector(square->color);
	new->size = square->size;
	new->shiny = square->shiny;
	new->calcul_a = 0;
	new->prev_origin = NULL;
	return (new);
}
