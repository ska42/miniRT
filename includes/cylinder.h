/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:58:19 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/23 22:43:37 by lmartin          ###   ########.fr       */
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
	s_vector	*difference;
	float		calcul_a;
	float		calcul_c;
	float		calcul_d;
	s_vector	*prev_origin;
}				s_cylinder;

s_cylinder	*new_cylinder(s_vector *vectors[2], float diameter, float height, int color);
void		free_cylinder(s_cylinder *cylinder);
s_cylinder	*cpy_cylinder(s_cylinder *cylinder);

#endif
