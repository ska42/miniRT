/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:46:39 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 23:55:24 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float			length_vectors(t_vector v)
{
	return (sqrt(product_vectors(v, v)));
}

float			distance_points(t_vector p1, t_vector p2)
{
	return (sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) *
(p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z)));
}

float			product_vectors(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
