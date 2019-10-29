/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:18:35 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:35:05 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CANVAS_H
# define CANVAS_H

# include <stdlib.h>

typedef	struct	t_canvas
{
	float	width;
	float	height;
	float	distance;
}				s_canvas;

s_canvas		*new_canvas(int width, int heigth, int distance);

#endif
