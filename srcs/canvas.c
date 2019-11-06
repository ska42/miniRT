/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:19:55 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 03:04:54 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

s_canvas		*new_canvas(float width, float heigth, float distance)
{
	s_canvas	*canvas;

	canvas = malloc(sizeof(s_canvas));
	canvas->width = width;
	canvas->height = heigth;
	canvas->distance = distance;
	return (canvas);
}
