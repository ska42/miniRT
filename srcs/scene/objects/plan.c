/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 05:25:49 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/01 00:22:58 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "plan.h"

s_plan		*new_plan(s_vector *p, s_vector *v, s_vector *c)
{
	s_plan	*plan;

	if (!(plan = malloc(sizeof(s_plan))))
		print_error_and_exit(-7);
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
	free(plan->color);
	if (plan->prev_origin)
		free(plan->prev_origin);
	free(plan);
}

s_plan		*cpy_plan(s_plan *plan)
{
	s_plan	*new;

	if (!(new = malloc(sizeof(s_plan))))
		print_error_and_exit(-7);
	new->point = cpy_vector(plan->point);
	new->normal = cpy_vector(plan->normal);
	new->color = cpy_vector(plan->color);
	new->shiny = plan->shiny;
	new->calcul_a = 0;
	new->prev_origin = NULL;
	return (new);
}
