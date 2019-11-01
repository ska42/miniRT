/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 06:45:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/01 07:01:07 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_vector	*color_to_rgb(unsigned int color)
{
	int red;
	int green;
	int blue;

	blue = color % 256;
	green = ((color - blue) / 256) % 256;
	red = ((color - blue) / (256 * 256)) - green / 256;
	return (new_vector(red, green, blue));
}


int			rgb_to_color(s_vector *rgb)
{
	int color;

	color = rgb->x;
	color = (color << 8) + rgb->y;
	color = (color << 8) + rgb->z;
	return (color);
}
