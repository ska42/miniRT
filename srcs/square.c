/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 05:10:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/05 09:31:29 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_square	*new_square(s_vector *center, s_vector *orientation, float size, int color)
{
	s_square *new;
	s_vector *angle;
	s_vector *origin;

	new = malloc(sizeof(s_square));
	new->center = center;
	new->orientation = orientation;
	new->size = size;
	new->color = color;
	angle = new_vector(orientation->x/1 * 180, orientation->y/1 * 180, orientation->z/1 * 180);
	origin = new_vector(1, 1, 1);
	rot(origin, angle);
	new->shiny = -1;
	new->reflective = -1;
	return (new);
}
