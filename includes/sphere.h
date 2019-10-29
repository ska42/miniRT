/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:09:23 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:35:44 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPHERE_H
# define SPHERE_H

# include <stdlib.h>
# include "vector.h"

typedef struct 	t_sphere
{
	float		radius;
	int			color;
	s_vector	*center;
}				s_sphere;

s_sphere		*new_sphere(float radius, int color, s_vector *center);
s_sphere		*new_default_sphere(float radius, int color);

#endif
