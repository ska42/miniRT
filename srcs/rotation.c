/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:54:10 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 04:24:12 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

s_rotation		*new_rotation(s_vector *rota_x, s_vector *rota_y, s_vector *rota_z)
{
	s_rotation	*rotation;

	rotation = malloc(sizeof(s_rotation));
	rotation->x = rota_x;
	rotation->y = rota_y;
	rotation->z = rota_z;
	return (rotation);
}
