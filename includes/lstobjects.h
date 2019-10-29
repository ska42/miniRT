/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobjects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:24:32 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:35:27 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LSTOBJECTS_H
# define LSTOBJECTS_H

# include <stdlib.h>

# define TYPE_SPHERE 0

typedef struct	t_lstobjects
{
	int		type;
	void	*object;
	void	*next;
}				s_lstobjects;

s_lstobjects		*new_obj(int type, void *object);

#endif
