/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 03:14:19 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 06:32:17 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "vector.h"

int		ft_atoi(char *line, int *nb);
int		ft_atof(char *line, float *nb);
int		ft_atoc(char *line, int *color);
int		ft_atov(char *line, s_vector **vector);

#endif
