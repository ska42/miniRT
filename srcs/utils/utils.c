/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:00:47 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/17 07:20:08 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

int		ft_atof(char *line, float *nb)
{
	int			i;
	float		sub_zero;

	if ((i = ft_atoi(line, (int *)nb)) < 0)
		return (-1);
	if (line[i] == '.')
		i++;
	sub_zero = (nb < 0) ? -0.1 : 0.1;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
	{
		*nb += sub_zero * line[i++] - '0';
		sub_zero *= 0.1;
	}
	return (i);
}

int		ft_atoc(char *line, int *color)
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
		else
			i++;
		n++;
	}
	*color = rgb[0];
	*color = (*color << 8) + rgb[1];
	*color = (*color << 8) + rgb[2];
	return (i);
}

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
