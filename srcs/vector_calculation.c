/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:46:39 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:30:24 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float			product_vectors(s_vector v1, s_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);;
}

s_vector		*add_vectors(s_vector v1, s_vector v2)
{
	return (new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

s_vector		*subtract_vectors(s_vector v1, s_vector v2)
{
	return (new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}


s_vector		*multiply_vectors(s_vector v1, s_vector v2)
{
	return (new_vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}
