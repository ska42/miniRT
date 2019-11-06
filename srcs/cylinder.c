/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:01:25 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 19:07:13 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_cylinder	*new_cylinder(s_vector *center, s_vector *orientation, float diameter, float height)
{
	s_cylinder	*new;

	new = malloc(sizeof(s_cylinder));
	new->center = center;
	new->orientation = orientation;
	new->diameter = diameter;
	new->height = height;
	new->color = 0xffffff;
	new->shiny = -1;
	new->reflective = -1;
	return (new);
}
