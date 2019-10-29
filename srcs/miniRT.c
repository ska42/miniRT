/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 08:33:41 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		main(int	argc, char *argv[])
{
	void		*mlx_ptr;
	void		*win_ptr;
	s_canvas	*viewport;

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init();
	viewport = new_canvas(500, 500, 1);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "miniRT");


	mlx_loop(mlx_ptr);
}
