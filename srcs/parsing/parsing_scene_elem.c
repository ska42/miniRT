/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:03:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/19 22:43:01 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		parsing_resolution(s_scene **scene, char *line)
{
	int i;
	int r;
	int res_x;
	int res_y;

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
	printf("viewport_working");
	return (!((*scene)->viewport = new_canvas(res_x, res_y, 1)) ? -1 : 0);
}

int		parsing_ambient_light(s_scene **scene, char *line)
{
	int		i;
	int		r;
	float	intensity;
	int		color;

	i = 1;
	if (line[i] != ' ' && line[i] != '\t')
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] < '0' || line[i] > '9') ||
(r = ft_atof(&line[i], &intensity)) < 0)
		return (-1);
	if ((i += r) > 0 && line[i] != ' ' && line[i] != '\t')
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] < '0' || line[i] > '9') || (r = ft_atoc(&line[i], &color)) < 0)
		return (-1);
	i += r;
	while (line[i] == ' ' || line[i] == '\t')
		if (line[++i] && line[i] != ' ' && line[i] != '\t')
			return (-1);
	printf("ambient_light_working");
	(*scene)->total_intensity += intensity;
	return ((!(add_back(&(*scene)->lights, TYPE_LIGHT,
new_default_light(TYPE_AMBIENT, intensity, color)))) ? 0 : -1);
}

int		parsing_point_light(s_scene **scene, char *l)
{
	int			i[4];
	s_vector	*pos;
	float		intensity;

	i[0] = 1;
	i[1] = 0;
	i[2] = 0;
	while (i[2] < 4 && (i[0] += i[1]) && (l[i[0]] == ' ' || l[i[0]] == '\t'))
	{
		while (l[i[0]] == ' ' || l[i[0]] == '\t')
			i[0]++;
		if ((i[2] == 0) && (((l[i[0]] < '0' || l[i[0]] > '9')
	 	&& l[i[0]] != '-') || (i[1] = ft_atov(&l[i[0]], &pos)) < 0))
			return (-1);
		if ((i[2] == 1) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[1] = ft_atof(&l[i[0]], &intensity)) < 0))
			return (free_and_return_minus_one(pos));
		if ((i[2]++ == 2) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[1] = ft_atoc(&l[i[0]], &i[3])) < 0))
			return (free_and_return_minus_one(pos));
	}
	if (l[i[0]] && l[i[0]] != ' ' && l[i[0]] != '\t')
		return (free_and_return_minus_one(pos));
	printf("point_light_working");
	(*scene)->total_intensity += intensity;
	return ((!(add_back(&(*scene)->lights, TYPE_LIGHT,
new_point_light(pos, intensity, i[3])))) ? 0 : free_and_return_minus_one(pos));
}

int		parsing_directional_light(s_scene **scene, char *line)
{
	(void)scene;
	(void)line;
	return (0);
}

int		parsing_camera(s_scene **scene, char *line)
{
	int			i;
	int			r;
	int			n;
	s_vector	*vectors[2];
	int			fov;

	i = 1;
	r = 0;
	n = -1;
	while (++n < 4 && (i += r) && line[i] && (line[i] == ' ' || line[i] == '\t'))
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if ((n < 2) && (((line[i] < '0' || line[i] > '9') && line[i] != '-') ||
		(r = ft_atov(&line[i], &vectors[n])) < 0))
			return (multiple_free_return(vectors, n - 1));
		if ((n == 2) && ((line[i] < '0' || line[i] > '9') ||
		(r = ft_atoi(&line[i], &fov)) < 0))
			return (multiple_free_return(vectors, 2));
	}
	if (line[i] && line[i] != ' ' && line[i] != '\t')
		return (multiple_free_return(vectors, 2));
	printf("camera_working");
	return ((!(add_back(&(*scene)->cameras, TYPE_CAMERA, new_camera(
vectors[0], vectors[1], fov))) ? 0 : multiple_free_return(vectors, 2)));
}
