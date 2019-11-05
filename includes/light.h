/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:29:23 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/05 04:53:12 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIGHT_H
# define LIGHT_H

# include <stdlib.h>
# include "vector.h"

# define TYPE_AMBIENT 0
# define TYPE_POINT 1
# define TYPE_DIRECTIONAL 2

typedef struct	t_light
{
	int			type;
	float		intensity;
	int			color;
	s_vector	*vector;
}				s_light;

s_light			*new_default_light(int type, float intensity);

#endif
