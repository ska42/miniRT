/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:56:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 05:02:05 by lmartin          ###   ########.fr       */
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
	s_vector		*rotation;
	int				fov;
}				s_camera;

s_camera		*new_camera(s_vector *pos, s_vector *rota, int fov);

#endif
