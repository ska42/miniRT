/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 23:03:59 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef BACKGROUND_COLOR
#  define BACKGROUND_COLOR 0x0
# endif

# ifndef LIMIT_RES_X
#  define LIMIT_RES_X 2560
# endif

# ifndef LIMIT_RES_Y
#  define LIMIT_RES_Y 1440
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <pthread.h>
# include <errno.h>
# include <stdio.h>

/**
**	minilibx
**/
# include "mlx.h"
# include "mlx_struct.h"

/**
**	utils
**/
# include "get_next_line.h"
# include "utils.h"
# include "no_leaks.h"
# include "error.h"
# include "export_bmp.h"

/**
**	parsing
**/
# include "parsing.h"

/**
**	scene
**/
# include "scene.h"
# include "camera.h"
# include "canvas.h"
# include "image.h"
# include "handle_key.h"

/**
**	objects
**/
# include "light.h"
# include "lstobjects.h"
# include "cylinder.h"
# include "plan.h"
# include "square.h"
# include "triangle.h"
# include "sphere.h"

/**
**	maths
**/
# include "vector.h"
# include "rotation.h"

/**
** raytracing
**/
# include "intersect.h"
# include "lightning.h"
# include "raytracing.h"
# include "reflect.h"

#endif
