/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobjects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:27:21 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 10:26:15 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstobjects.h"

s_lstobjects		*new_obj(int type, void *object)
{
	s_lstobjects *obj;

	obj = malloc(sizeof(s_lstobjects));
	obj->type	= type;
	obj->object = object;
	obj->next	= NULL;
	return (obj);
}

void				add_back(s_lstobjects **lst, int type, void *object)
{
	s_lstobjects *begin;

	begin = *lst;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new_obj(type, object);
	}
	else
		*lst = new_obj(type, object);
}
