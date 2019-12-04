/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:20:25 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:19 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCT_H
# define MLX_STRUCT_H

# include "scene.h"

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	t_scene *scene;
}				t_mlx;

#endif
