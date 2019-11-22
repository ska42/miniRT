/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 05:10:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 05:58:06 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_square	*new_square(s_vector *center, s_vector *orientation, float size, int color)
{
	s_square	*new;
	//s_vector	*angle;
	s_vector	*vector[4];

	new = malloc(sizeof(s_square));
	new->center = center;
	new->orientation = orientation;
	new->size = size;
	new->color = color;
	//angle = new_vector(orientation->x/1 * 180, orientation->y/1 * 180, orientation->z/1 * 180);
	vector[0] = new_vector(new->size / 2, new->size / 2, 0);
	vector[1] = new_vector(- (new->size / 2), (new->size / 2), 0);
	vector[2] = new_vector( (new->size / 2), - (new->size / 2), 0);
	vector[3] = new_vector(- (new->size / 2), -(new->size / 2), 0);
	rot(vector[0], orientation);
	rot(vector[1], orientation);
	rot(vector[2], orientation);
	rot(vector[3], orientation);
	new->a = add_vectors(*vector[0], *new->center);
	new->b = add_vectors(*vector[1], *new->center);
	new->c = add_vectors(*vector[2], *new->center);
	new->d = add_vectors(*vector[3], *new->center);
	new->ab = subtract_vectors(*new->b, *new->a);
	new->ac = subtract_vectors(*new->c, *new->a);
	new->normal = cross(*new->ab, *new->ac);
	new->shiny = -1;
	new->reflective = -1;
	new->calcul_a = 0;
	new->prev_origin = NULL;
	return (new);
}

void		free_square(s_square *square)
{
	free(square->center);
	free(square->orientation);
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

	new = malloc(sizeof(s_square));
	new->center = cpy_vector(square->center);
	new->orientation = cpy_vector(square->orientation);
	new->a = cpy_vector(square->a);
	new->b = cpy_vector(square->b);
	new->c = cpy_vector(square->c);
	new->d = cpy_vector(square->d);
	new->ab = cpy_vector(square->ab);
	new->ac = cpy_vector(square->ac);
	new->normal = cpy_vector(square->normal);
	new->size = square->size;
	new->color = square->color;
	new->shiny = square->shiny;
	new->reflective = square->reflective;
	new->calcul_a = 0;
	new->prev_origin = NULL;
	return (new);
}
