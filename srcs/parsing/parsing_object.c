/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:59:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 08:11:02 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		parsing_sphere(s_scene **scene, char *line)
{
	int			i;
	int			n;
	int			r;
	s_vector	*center;
	float		radius;
	int			color;

	i = 2;
	n = 0;
	while (n < 4)
	{
		n++;
	}
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_plan(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_square(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_triangle(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_cylinder(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}
