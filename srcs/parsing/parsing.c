/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:05:57 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 07:50:33 by lmartin          ###   ########.fr       */
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
			printf("ok\n");
		else if (line[0] == 'c')
			return (parsing_camera(scene, line));
		else if (line[0] == 'l')
			return (parsing_point_light(scene, line));
		else if (line[0] == 's' && line[1] == 'p')
			printf("ok\n");
		else if (line[0] == 's' && line[1] == 'q')
			printf("ok\n");
		else if (line[0] == 'p' && line[1] == 'l')
			printf("ok\n");
		else if (line[0] == 't' && line[1] == 'r')
			printf("ok\n");
		else
			return (-1);
	}
	return (0);
}

s_scene		*parsing(int fd)
{
	int		ret;
	char	*line;
	s_scene	*scene;

	scene = new_empty_scene(BACKGROUND_COLOR);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (choice_parsing(&scene, line) < 0)
		{
			free(line);
			return (NULL);
		}
		free(line);
	}
	if (ret < 0)
		return (NULL);
	else
	{
		if (choice_parsing(&scene, line) < 0)
		{
			free(line);
			return (NULL);
		}
		free(line);
	}
	return (scene);
}
