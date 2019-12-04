/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobjects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:24:32 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:31:45 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTOBJECTS_H
# define LSTOBJECTS_H

# include <stdlib.h>

# define TYPE_SPHERE 0
# define TYPE_PLAN 1
# define TYPE_SQUARE 2
# define TYPE_TRIANGLE 3
# define TYPE_CYLINDER 4
# define TYPE_LIGHT 5
# define TYPE_CAMERA 6

typedef struct		s_lstobjects
{
	int				type;
	void			*object;
	float			reflective;
	void			*prev;
	void			*next;
}					t_lstobjects;

t_lstobjects		*new_obj(int type, void *object, float reflective);
int					add_back(t_lstobjects **lst, int type, void *object,
float reflective);
t_lstobjects		*cpy_lstobjects(t_lstobjects *obj);

#endif
