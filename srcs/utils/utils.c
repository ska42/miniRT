/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:00:47 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 21:28:49 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
** FT_ATOI
** ascii to integer
*/

int		ft_atoi(char *line, int *nb)
{
	int		i;
	long	nnb;

	i = 0;
	nnb = 0;
	if (line[i] == '-')
		i++;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		nnb = 10 * nnb + (line[i++] - '0');
	if (i == 0 || (line[0] == '-' && i == 1))
		return (-1);
	*nb = (line[0] == '-') ? -nnb : nnb;
	return (i);
}

/*
** FT_ATOF
** ascii to float
*/

int		ft_atof(char *line, float *nb)
{
	int			i;
	int			nnb;
	float		sub_zero;

	if ((i = ft_atoi(line, &nnb)) < 0)
		return (-1);
	*nb = nnb;
	if (line[i] == '.')
		i++;
	sub_zero = (nb < 0) ? -0.1 : 0.1;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
	{
		*nb += sub_zero * (line[i++] - '0');
		sub_zero *= 0.1;
	}
	return (i);
}

/*
** FT_ATOC
** ascii to color (s_vector color)
** Note : The difference with ft_atov is that it check for integer
** between 0 and 255.
*/

int		ft_atoc(char *line, s_vector **color)
{
	int i;
	int r;
	int n;
	int rgb[3];

	i = 0;
	n = 0;
	while (n < 3)
	{
		if ((r = ft_atoi(&line[i], &rgb[n])) < 0)
			return (-1);
		if (rgb[n] < 0 || rgb[n] > 255)
			return (-1);
		i += r;
		if (n < 2 && line[i] != ',')
			return (-1);
		else if (n < 2 && line[i] == ',')
			i++;
		n++;
	}
	*color = new_vector(rgb[0], rgb[1], rgb[2]);
	return (i);
}

/*
** FT_ATOV
** ascii to vector (s_vector vector)
** Note : The difference with ft_atoc is that it check for float.
*/

int		ft_atov(char *line, s_vector **vector)
{
	int i;
	int r;
	int n;
	float v[3];

	i = 0;
	n = 0;
	while (n < 3)
	{
		if ((r = ft_atof(&line[i], &v[n])) < 0)
			return (-1);
		i += r;
		if (n < 2 && line[i] != ',')
			return (-1);
		else if (n < 2 && line[i] == ',')
			i++;
		n++;
	}
	if (!(*vector = new_vector(v[0], v[1], v[2])))
		return (-1);
	return (i);
}
