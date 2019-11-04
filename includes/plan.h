/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:20:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 06:13:07 by lmartin          ###   ########.fr       */
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
}				s_plan;

s_plan		*new_plan(s_vector *p, s_vector	*v, int c);

#endif
