/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:00:47 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 03:14:57 by lmartin          ###   ########.fr       */
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
		nnb = 10 * nnb + (line[i++] + '0');
	if (i == 0 || (line[0] == '-' && i == 1))
		return (-1);
	*nb = (line[0] == '-') ? -nnb : nnb;
	return (i);
}

float	ft_atof()
{
	return (0);
}
