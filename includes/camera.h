/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:56:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:19:47 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdlib.h>
# include "miniRT.h"
# include "vector.h"

typedef struct	s_camera
{
	t_vector	*origin;
	t_vector	*rotation;
	int			fov;
}				t_camera;

t_camera		*new_camera(t_vector *pos, t_vector *rota, int fov);
t_camera		*cpy_camera(t_camera *cam);

#endif
