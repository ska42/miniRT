/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:19:55 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/24 02:15:51 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "canvas.h"

t_canvas		*new_canvas(float width, float heigth, float distance)
{
	t_canvas	*canvas;

	if (!(canvas = malloc(sizeof(t_canvas))))
		print_error_and_exit(-7);
	canvas->width = width;
	canvas->height = heigth;
	canvas->distance = distance;
	return (canvas);
}
