/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:01:25 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/14 05:20:32 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_cylinder	*new_cylinder(s_vector *center, s_vector *orientation, float diameter, float height)
{
	s_cylinder	*new;
	s_vector 	*angle;
	s_vector	*vector[2];

	new = malloc(sizeof(s_cylinder));
	new->center = center;
	new->orientation = orientation;
	angle = new_vector(orientation->x/1 * 180, orientation->y/1 * 180, orientation->z/1 * 180);
	vector[0] = new_vector(0, center->y + height/2, 0);
	vector[1] = new_vector(0, center->y - height/2, 0);
	rot(vector[0], angle);
	rot(vector[1], angle);
	new->point1 = add_vectors(*vector[0], *center);
	new->point2 = add_vectors(*vector[1], *center);
	new->diameter = diameter;
	new->height = height;
	new->color = 0xffffff;
	new->shiny = -1;
	new->reflective = -1;
	return (new);
}
