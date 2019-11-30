/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bmp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:39:27 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 21:21:11 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_BMP_H
# define EXPORT_BMP_H

# include "mlx_struct.h"

# define HEADER_SIZE 122

void	fill_bmp(char **data, s_mlx *my_mlx);
void	header_bmp(char **data, s_mlx *my_mlx);
void	export_bmp(char *filename, s_mlx *my_mlx);

#endif
