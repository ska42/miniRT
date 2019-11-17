/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:19:55 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/17 05:52:41 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

s_canvas		*new_canvas(float width, float heigth, float distance)
{
	s_canvas	*canvas;

	if (!(canvas = malloc(sizeof(s_canvas))))
		return (NULL);
	canvas->width = width;
	canvas->height = heigth;
	canvas->distance = distance;
	return (canvas);
}
