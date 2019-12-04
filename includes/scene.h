/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 06:37:11 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:24 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdlib.h>
# include "canvas.h"
# include "lstobjects.h"
# include "vector.h"

typedef struct		s_scene
{
	t_vector		*origin;
	t_canvas		*viewport;
	t_canvas		*viewplane;
	t_lstobjects	*cameras;
	t_lstobjects	*objects;
	t_lstobjects	*lights;
	float			total_intensity;
	int				nb_camera;
	int				background_color;
	int				depth;
	float			t_min;
	float			t_max;
}					t_scene;

t_scene				*new_empty_scene(int color);
t_scene				*new_scene(t_lstobjects *cameras, t_lstobjects *objects,
t_lstobjects *lights, int color);
t_scene				*cpy_scene(t_scene *scene);
int					free_cpy_scene(t_scene *scene);

#endif
