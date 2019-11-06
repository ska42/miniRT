/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobjects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:24:32 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/06 19:09:08 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LSTOBJECTS_H
# define LSTOBJECTS_H

# include <stdlib.h>

# define TYPE_SPHERE 0
# define TYPE_PLAN 1
# define TYPE_SQUARE 2
# define TYPE_TRIANGLE 3
# define TYPE_CYLINDER 4
# define TYPE_LIGHT 5

typedef struct	t_lstobjects
{
	int		type;
	void	*object;
	void	*next;
}				s_lstobjects;

s_lstobjects		*new_obj(int type, void *object);
void				add_back(s_lstobjects **lst, int type, void *object);

#endif
