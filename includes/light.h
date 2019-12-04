/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:29:23 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:17 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include <stdlib.h>
# include "vector.h"

# define TYPE_AMBIENT 0
# define TYPE_POINT 1
# define TYPE_DIRECTIONAL 2

typedef struct	s_light
{
	int			type;
	float		intensity;
	t_vector	*color;
	t_vector	*vector;
}				t_light;

t_light			*new_default_light(int type, float intensity, t_vector *color);
t_light			*new_point_light(t_vector *pos, float intensity,
t_vector *color);

#endif
