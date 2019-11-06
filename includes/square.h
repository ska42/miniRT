/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:57:24 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 00:05:38 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include <stdlib.h>
# include "vector.h"

typedef struct	t_square
{
	s_vector	*center;
	s_vector	*orientation;
	s_vector	*a;
	s_vector	*b;
	s_vector	*c;
	s_vector	*d;
	float		size;
	int			color;
	float		shiny;
	float		reflective;
}				s_square;

s_square	*new_square(s_vector *center, s_vector *orientation, float size, int color);

#endif
