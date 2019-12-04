/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:18:35 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:29:59 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <stdlib.h>

typedef	struct	s_canvas
{
	float		width;
	float		height;
	float		distance;
}				t_canvas;

t_canvas		*new_canvas(float width, float heigth, float distance);

#endif
