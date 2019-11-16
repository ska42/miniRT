/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 05:10:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/14 04:53:05 by lmartin          ###   ########.fr       */
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
	new->shiny = -1;
	new->reflective = -1;
	return (new);
}
