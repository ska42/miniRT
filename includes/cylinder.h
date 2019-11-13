/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:58:19 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/12 21:39:45 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include <stdlib.h>
# include "vector.h"

typedef struct	t_cylinder
{
	s_vector	*center;
	s_vector	*orientation;
	s_vector	*point1;
	s_vector	*point2;
	float		diameter;
	float		height;
	int			color;
	float		shiny;
	float		reflective;
}				s_cylinder;

s_cylinder	*new_cylinder(s_vector *center, s_vector *orientation, float diameter, float height);

#endif
