/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:49:08 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 10:39:52 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATION_H
# define ROTATION_H

#include "vector.h"

void		rx(s_vector *vect, float x);
void		ry(s_vector *vect, float y);
void		rz(s_vector *vect, float z);
void		rot(s_vector *vect, s_vector *angle);
void		anti_rot(s_vector *vect, s_vector *angle);

#endif
