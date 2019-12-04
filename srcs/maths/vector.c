/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:06:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/24 02:23:41 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "vector.h"

t_vector		*new_vector(float x, float y, float z)
{
	t_vector	*vector;

	if (!(vector = malloc(sizeof(t_vector))))
		print_error_and_exit(-7);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector		*cpy_vector(t_vector *vector)
{
	return (new_vector(vector->x, vector->y, vector->z));
}

int				is_equal(t_vector *a, t_vector *b)
{
	return ((a->x == b->x && a->y == b->y && a->z == b->z));
}
