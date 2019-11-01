/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:06:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/01 12:40:38 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			set_vector(s_vector *vector, float x, float y, float z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}

s_vector		*new_vector(float x, float y, float z)
{
	s_vector	*vector;

	vector = malloc(sizeof(s_vector));
	set_vector(vector, x, y, z);
	return (vector);
}
