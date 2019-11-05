/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:57:24 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/05 09:19:10 by lmartin          ###   ########.fr       */
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
	s_vector	*pos_d1;
	s_vector	*pos_d2;
	float		size;
	int			color;
	float		shiny;
	float		reflective;
}				s_square;

s_square	*new_square(s_vector *center, s_vector *orientation, float size, int color);

#endif
