/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 23:55:16 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:56:04 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		*cross(t_vector u, t_vector v)
{
	return (new_vector(u.y * v.z - u.z * v.y,
u.z * v.z - u.x * v.z, u.x * v.y - u.y * v.x));
}

t_vector		*product_scalar(t_vector u, t_vector v)
{
	return (new_vector(u.y * v.z - u.z * v.x,
u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x));
}

t_vector		*add_vectors(t_vector v1, t_vector v2)
{
	return (new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector		*subtract_vectors(t_vector v1, t_vector v2)
{
	return (new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector		*multiply_vectors(float k, t_vector v2)
{
	return (new_vector((k * v2.x), (k * v2.y), (k * v2.z)));
}
