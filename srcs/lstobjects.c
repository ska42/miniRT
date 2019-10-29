/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobjects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:27:21 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:30:15 by lmartin          ###   ########.fr       */
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
