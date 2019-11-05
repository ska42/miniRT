/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/05 05:10:41 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef BACKGROUND_COLOR
#  define BACKGROUND_COLOR 0x0
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "camera.h"
# include "canvas.h"
# include "intersect.h"
# include "light.h"
# include "lightning.h"
# include "lstobjects.h"
# include "plan.h"
# include "sphere.h"
# include "vector.h"
# include "raytracing.h"
# include "scene.h"
# include "square.h"
# include "reflect.h"
# include "rotation.h"
# include "mlx.h"

#endif
