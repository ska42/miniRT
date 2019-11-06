/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:58:19 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 18:59:49 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include <stdlib.h>
# include "vector.h"

typedef struct	t_triangle
{
	s_vector	*center;
	s_vector	*orientation;
	s_vector	*diameter;
	s_vector	*height;
	int			color;
	float		shiny;
	float		reflective;
}				s_triangle;

#endif
