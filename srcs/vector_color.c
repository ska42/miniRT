/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 06:45:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/01 13:07:58 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_vector	*color_to_rgb(unsigned int color)
{
	int red;
	int green;
	int blue;

	blue = (int)(color % 256);
	green = (int)(((color - blue) / 256) % 256);
	red = (int)(((color - blue) / (256 * 256)) - green / 256);
	return (new_vector((float)red, (float)green, (float)blue));
}


int			rgb_to_color(s_vector *rgb)
{
	int color;

	color = (int)(((int)rgb->x));
	color = (int)((color << 8) + (int)rgb->y);
	color = (int)((color << 8) + (int)rgb->z);
	return (color);
}
