/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:05:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/23 22:50:18 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int			choice_parsing(s_scene **scene, char *line)
{
	if (line[0] != '\0')
	{
		if (line[0] == 'R')
			return (parsing_resolution(scene, line));
		else if (line[0] == 'A')
			return (parsing_ambient_light(scene, line));
		else if (line[0] == 'c' && line[1] == 'y')
			return (parsing_cylinder(scene, line));
		else if (line[0] == 'c')
			return (parsing_camera(scene, line));
		else if (line[0] == 'l')
			return (parsing_point_light(scene, line));
		else if (line[0] == 's' && line[1] == 'p')
			return (parsing_sphere(scene, line));
		else if (line[0] == 's' && line[1] == 'q')
			return (parsing_square(scene, line));
		else if (line[0] == 'p' && line[1] == 'l')
			return (parsing_plan(scene, line));
		else if (line[0] == 't' && line[1] == 'r')
			return (parsing_triangle(scene, line));
		else
			return (-1);
	}
	return (0);
}

s_scene		*parsing(int fd)
{
	int		ret;
	int		nb_cam;
	char	*line;
	s_scene	*scene;
	s_lstobjects *cameras;

	scene = new_empty_scene(BACKGROUND_COLOR);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (choice_parsing(&scene, line) < 0)
		{
			free(line);
			return (NULL);
		}
		printf("\n");
		free(line);
	}
	if (ret < 0 || choice_parsing(&scene, line) < 0)
	{
		free(line);
		return (NULL);
	}
	nb_cam = 1;
	cameras = scene->cameras;
	while (cameras->next)
	{
		((s_lstobjects *)cameras->next)->prev = cameras;
		nb_cam++;
		cameras = cameras->next;
	}
	cameras->next = scene->cameras;
	scene->cameras->prev = cameras;
	scene->nb_camera = nb_cam;
	free(line);
	return (scene);
}
