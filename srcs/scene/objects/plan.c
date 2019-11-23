/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:25:49 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/23 22:48:09 by lmartin          ###   ########.fr       */
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
	plan->color = c;
	plan->calcul_a = 0;
	plan->prev_origin = NULL;
	return (plan);
}

void		free_plan(s_plan *plan)
{
	free(plan->point);
	free(plan->normal);
	if (plan->prev_origin)
		free(plan->prev_origin);
	free(plan);
}

s_plan		*cpy_plan(s_plan *plan)
{
	s_plan	*new;

	new = malloc(sizeof(s_plan));
	new->point = cpy_vector(plan->point);
	new->normal = cpy_vector(plan->normal);
	new->shiny = plan->shiny;
	new->color = plan->color;
	new->calcul_a = 0;
	new->prev_origin = NULL;
	return (new);
}
