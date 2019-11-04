/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:56:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 04:23:51 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdlib.h>
#include "miniRT.h"
#include "vector.h"

typedef struct 	t_camera
{
	s_vector		*origin;
	s_rotation		*rotation;
}				s_camera;

s_camera		*new_camera(s_vector *pos, s_vector *rota_x, s_vector *rota_y, s_vector *rota_z);

#endif
