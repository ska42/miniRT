/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:49:08 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:24 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATION_H
# define ROTATION_H

# include "vector.h"

void		rx(t_vector *vect, float x);
void		ry(t_vector *vect, float y);
void		rz(t_vector *vect, float z);
void		rot(t_vector *vect, t_vector *angle);
void		anti_rot(t_vector *vect, t_vector *angle);

#endif
