/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobjects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:27:21 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 06:20:01 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstobjects.h"

s_lstobjects		*new_obj(int type, void *object)
{
	s_lstobjects *obj;

	if (!(obj = malloc(sizeof(s_lstobjects))))
		return (NULL);
	obj->type	= type;
	obj->object = object;
	obj->next	= NULL;
	return (obj);
}

int					add_back(s_lstobjects **lst, int type, void *object)
{
	s_lstobjects *begin;

	if (!object)
		return (-1);
	begin = *lst;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		if (!(begin->next = new_obj(type, object)))
			return (-1);
	}
	else
		*lst = new_obj(type, object);
	return (0);
}
