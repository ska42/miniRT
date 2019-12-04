/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobjects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:27:21 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:16:55 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lstobjects.h"

t_lstobjects		*new_obj(int type, void *object, float reflective)
{
	t_lstobjects *obj;

	if (!(obj = malloc(sizeof(t_lstobjects))))
		print_error_and_exit(-7);
	obj->type = type;
	obj->object = object;
	obj->reflective = reflective;
	obj->next = NULL;
	return (obj);
}

int					add_back(t_lstobjects **lst, int type, void *object,
float reflective)
{
	t_lstobjects *begin;

	if (!object)
		return (-1);
	begin = *lst;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		if (!(begin->next = new_obj(type, object, reflective)))
			return (-1);
	}
	else
	{
		*lst = new_obj(type, object, reflective);
		begin = *lst;
	}
	return (0);
}

t_lstobjects		*cpy_lstobjects(t_lstobjects *obj)
{
	return (new_obj(obj->type, obj->object, obj->reflective));
}
