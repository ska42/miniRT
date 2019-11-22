/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:20:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 05:52:02 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PLAN_H
# define PLAN_H

# include <stdlib.h>
# include "vector.h"

typedef struct 	t_plan
{
	s_vector	*point;
	s_vector	*normal;
	float		shiny;
	float		reflective;
	int			color;
	float		calcul_a;
	s_vector	*prev_origin;
}				s_plan;

s_plan		*new_plan(s_vector *p, s_vector	*v, int c);
void		free_plan(s_plan *plan);
s_plan		*cpy_plan(s_plan *plan);

#endif
