/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:46:39 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 17:53:25 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float			length_vectors(s_vector v)
{
	return (sqrt(product_vectors(v, v)));
}

float			product_vectors(s_vector v1, s_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);;
}

s_vector		*cross(s_vector u, s_vector v)
{
	return(new_vector(u.y * v.z - u.z * v.y, u.z * v.z - u.x * v.z, u.x * v.y - u.y * v.x));
}

s_vector		*product_scalar(s_vector u, s_vector v)
{
	return(new_vector(u.y * v.z - u.z * v.x, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x));
}

s_vector		*add_vectors(s_vector v1, s_vector v2)
{
	return (new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

s_vector		*subtract_vectors(s_vector v1, s_vector v2)
{
	return (new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

s_vector		*multiply_vectors(float k, s_vector v2)
{
	return (new_vector((k * v2.x), (k * v2.y), (k * v2.z)));
}
