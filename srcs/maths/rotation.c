/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:48:08 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:55:56 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rx(t_vector *vect, float x)
{
	t_vector	tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos(x) - vect->z * sin(x);
	tmp.z = vect->y * sin(x) + vect->z * cos(x);
	*vect = tmp;
}

void		ry(t_vector *vect, float y)
{
	t_vector	tmp;

	tmp.x = vect->x * cos(y) + vect->z * sin(y);
	tmp.y = vect->y;
	tmp.z = vect->x * -sin(y) + vect->z * cos(y);
	*vect = tmp;
}

void		rz(t_vector *vect, float z)
{
	t_vector	tmp;

	tmp.x = vect->x * cos(z) - vect->y * sin(z);
	tmp.y = vect->x * sin(z) + vect->y * cos(z);
	tmp.z = vect->z;
	*vect = tmp;
}

void		rot(t_vector *vect, t_vector *angle)
{
	rx(vect, angle->x);
	ry(vect, angle->y);
	rz(vect, angle->z);
}

void		anti_rot(t_vector *vect, t_vector *angle)
{
	rz(vect, -angle->z);
	ry(vect, -angle->y);
	rx(vect, -angle->x);
}
