/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:59:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/17 08:08:14 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		parsing_sphere(s_scene **scene, char *l)
{
	int			i[3];
	s_vector	*center;
	float		radius;
	int			color;

	i[0] = 2;
	i[2] = 0;
	i[1] = -1;
	while (++i[1] < 4 && (i[0] += i[2]) && (l[i[0]] == ' ' || l[i[0]] == '\t'))
	{
		while (l[i[0]] == ' ' || l[i[0]] == '\t')
			i[0]++;
		if (!i[1] && (((l[i[0]] < '0' || l[i[0]] > '9') && l[i[0]] != '-')
		|| (i[2] = ft_atov(&l[i[0]], &center)) < 0))
			return (-1);
		if ((i[1] == 1) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[2] = ft_atof(&l[i[0]], &radius)) < 0))
			return (free_and_return_minus_one(center));
		if ((i[1] == 2) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[2] = ft_atoc(&l[i[0]], &color)) < 0))
			return (free_and_return_minus_one(center));
	}
	if (l[i[0]] && l[i[0]] != ' ' && l[i[0]] != '\t')
		return (free_and_return_minus_one(center));
	printf("sphere_working");
	return (!l[i[0]] && (!(add_back(&(*scene)->objects, TYPE_SPHERE, new_sphere(
	radius, color, 10, center))) ? 0 : free_and_return_minus_one(center)));
}

int		parsing_plan(s_scene **scene, char *line)
{
	int			i;
	int			r;
	int			n;
	s_vector	*vectors[2];
	int			color;

	i = 2;
	r = 0;
	n = -1;
	while (++n < 4 && (i += r) > 0 && (line[i] == ' ' || line[i] == '\t'))
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if ((n < 2) && (((line[i] < '0' || line[i] > '9') && line[i] != '-') ||
		(r = ft_atov(&line[i], &vectors[n])) < 0))
			return (multiple_free_return(vectors, n - 1));
		if ((n == 2) && ((line[i] < '0' || line[i] > '9') ||
		(r = ft_atoc(&line[i], &color)) < 0))
			return (multiple_free_return(vectors, 2));
	}
	if (line[i] && line[i] != ' ' && line[i] != '\t')
		return (multiple_free_return(vectors, 2));
	printf("plan_working");
	return ((!(add_back(&(*scene)->objects, TYPE_PLAN, new_plan(
vectors[0], vectors[1], color))) ? 0 : multiple_free_return(vectors, 2)));
}

int		parsing_square(s_scene **scene, char *l)
{
	int			i[4];
	s_vector	*vectors[2];
	float		size;

	i[0] = 2;
	i[2] = 0;
	i[1] = -1;
	while (++i[1] < 5 && (i[0] += i[2]) && (l[i[0]] == ' ' || l[i[0]] == '\t'))
	{
		while (l[i[0]] == ' ' || l[i[0]] == '\t')
			i[0]++;
		if ((i[1] < 2) && (((l[i[0]] < '0' || l[i[0]] > '9') && l[i[0]] != '-') ||
		(i[2] = ft_atov(&l[i[0]], &vectors[i[1]])) < 0))
			return (multiple_free_return(vectors, i[1] - 1));
		if ((i[1] == 2) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[2] = ft_atof(&l[i[0]], &size)) < 0))
			return (multiple_free_return(vectors, 2));
		if ((i[1] == 3) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[2] = ft_atoc(&l[i[0]], &i[3])) < 0))
			return (multiple_free_return(vectors, 2));
	}
	if (l[i[0]] && l[i[0]] != ' ' && l[i[0]] != '\t')
		return (multiple_free_return(vectors, 2));
	printf("square_working");
	return ((!(add_back(&(*scene)->objects, TYPE_SQUARE, new_square(
vectors[0], vectors[1], size, i[3]))) ? 0 : multiple_free_return(vectors, 2)));
}

int		parsing_triangle(s_scene **scene, char *l)
{
	int			i[4];
	s_vector	*vec[3];

	i[0] = 2;
	i[2] = 0;
	i[1] = -1;
	while (++i[1] < 5 && (i[0] += i[2]) && (l[i[0]] == ' ' || l[i[0]] == '\t'))
	{
		while (l[i[0]] == ' ' || l[i[0]] == '\t')
			i[0]++;
		if ((i[1] < 3) && (((l[i[0]] < '0' || l[i[0]] > '9') && l[i[0]] != '-') ||
		(i[2] = ft_atov(&l[i[0]], &vec[i[1]])) < 0))
			return (multiple_free_return(vec, i[1] - 1));
		if ((i[1] == 3) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[2] = ft_atoc(&l[i[0]], &i[3])) < 0))
			return (multiple_free_return(vec, 3));
	}
	if (l[i[0]] && l[i[0]] != ' ' && l[i[0]] != '\t')
		return (multiple_free_return(vec, 3));
	printf("triangle_working");
	return ((!(add_back(&(*scene)->objects, TYPE_TRIANGLE, new_triangle(
vec[0], vec[1], vec[2], i[3]))) ? 0 : multiple_free_return(vec, 2)));
}

int		parsing_cylinder(s_scene **scene, char *l)
{
	int			i[4];
	s_vector	*vec[2];
	float		j[2];

	i[0] = 2;
	i[2] = 0;
	i[1] = -1;
	while (++i[1] < 6 && (i[0] += i[2]) && (l[i[0]] == ' ' || l[i[0]] == '\t'))
	{
		while (l[i[0]] == ' ' || l[i[0]] == '\t')
			i[0]++;
		if ((i[1] < 2) && (((l[i[0]] < '0' || l[i[0]] > '9') && l[i[0]] != '-') ||
		(i[2] = ft_atov(&l[i[0]], &vec[i[1]])) < 0))
			return (multiple_free_return(vec, i[1] - 1));
		if ((i[1] == 2) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[2] = ft_atoc(&l[i[0]], &i[3])) < 0))
			return (multiple_free_return(vec, 2));
		if ((i[1] > 2 && i[1] < 5) && ((l[i[0]] < '0' || l[i[0]] > '9') ||
		(i[2] = ft_atof(&l[i[0]], &j[i[1] - 3])) < 0))
			return (multiple_free_return(vec, 2));
	}
	if (l[i[0]] && l[i[0]] != ' ' && l[i[0]] != '\t')
		return (multiple_free_return(vec, 2));
	printf("cylinder_working");
	return ((!(add_back(&(*scene)->objects, TYPE_CYLINDER, new_cylinder(
vec, j[0], j[1], i[3]))) ? 0 : multiple_free_return(vec, 2)));
}
