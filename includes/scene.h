/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 06:37:11 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/02 07:19:39 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdlib.h>
# include "lstobjects.h"
# include "vector.h"

typedef struct 	t_scene
{
	s_vector		*origin;
	s_lstobjects	*objects;
	s_lstobjects	*lights;
	int				background_color;
	float			t_min;
	float			t_max;
}				s_scene;

s_scene		*new_scene(s_vector *origin, s_lstobjects *objects,
s_lstobjects *lights, int color);

#endif
