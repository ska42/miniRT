/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:48:08 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 10:39:27 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		rx(s_vector *vect, float x)
{
  s_vector	tmp;

  tmp.x = vect->x;
  tmp.y = vect->y * cos(x) - vect->z * sin(x);
  tmp.z = vect->y * sin(x) + vect->z * cos(x);
  *vect = tmp;
}

void		ry(s_vector *vect, float y)
{
  s_vector	tmp;

  tmp.x = vect->x * cos(y) + vect->z * sin(y);
  tmp.y = vect->y;
  tmp.z = vect->x * -sin(y) + vect->z * cos(y);
  *vect = tmp;
}

void		rz(s_vector *vect, float z)
{
  s_vector	tmp;

  tmp.x = vect->x * cos(z) - vect->y * sin(z);
  tmp.y = vect->x * sin(z) + vect->y * cos(z);
  tmp.z = vect->z;
  *vect = tmp;
}

void		rot(s_vector *vect, s_vector *angle)
{
  rx(vect, angle->x);
  ry(vect, angle->y);
  rz(vect, angle->z);
}

void		anti_rot(s_vector *vect, s_vector *angle)
{
  rz(vect, -angle->z);
  ry(vect, -angle->y);
  rx(vect, -angle->x);
}
