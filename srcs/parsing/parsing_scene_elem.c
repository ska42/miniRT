/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:03:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 03:18:26 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		parsing_resolution(s_scene **scene, char *line)
{
	int i;
	int r;
	int res_x;
	int res_y;

	res_x = 0;
	res_y = 0;
	i = 1;
	if (line[i] != ' ' && line[i] != '\t')
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] < '0' || line[i] > '9') || (r = ft_atoi(&line[i], &res_x)) < 0)
		return (-1);
	if ((i += r) > 0 && line[i] != ' ' && line[i] != '\t')
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] < '0' || line[i] > '9') || (r = ft_atoi(&line[i], &res_y)) < 0)
		return (-1);
	i += r;
	while (line[i] == ' ' || line[i] == '\t')
		if (line[++i] && line[i] != ' ' && line[i] != '\t')
			return (-1);
	return (!((*scene)->viewport = new_canvas(res_x, res_y, 1)) ? -1 : 0);
}

int		parsing_ambiant_light(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_point_light(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_directional_light(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_camera(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}
