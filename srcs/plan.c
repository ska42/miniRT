/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:25:49 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 10:54:52 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plan.h"

s_plan		*new_plan(s_vector *p, s_vector	*v, int c)
{
	s_plan	*plan;

	plan = malloc(sizeof(s_plan));
	plan->point = p;
	plan->normal = v;
	plan->shiny = -1;
	plan->reflective = -1;
	plan->color = c;
	return (plan);
}
