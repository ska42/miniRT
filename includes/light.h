/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:29:23 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/23 23:52:16 by lmartin          ###   ########.fr       */
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
	s_vector	*color;
	s_vector	*vector;
}				s_light;

s_light			*new_default_light(int type, float intensity, s_vector *color);
s_light			*new_point_light(s_vector *pos, float intensity, s_vector *color);

#endif
