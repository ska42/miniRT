/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/01 08:07:49 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"



int		main(int	argc, char *argv[])
{
	void			*mlx_ptr;
	void			*win_ptr;
	s_canvas		*viewport;
	s_vector		*obs;
	s_vector		*direction;
	s_lstobjects	*lstobj;
	s_lstobjects	*lstlight;
	int				color;
	float			x;
	float			y;
	float			t_min_max[2];
	int				i;

	(void)argc;
	(void)argv;
	/**	WINDOW **/
	mlx_ptr = mlx_init();
	viewport = new_canvas(500, 500, 1);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "miniRT");
	/** SPHERES & O **/
	obs = new_vector(0, 0, 0);
	lstobj = new_obj(TYPE_SPHERE, new_default_sphere(1, 0xbf3eff));
	set_vector(((s_sphere *)lstobj->object)->center, 0, -1, 3);
	lstobj->next = new_obj(TYPE_SPHERE, new_default_sphere(1, 0x6400));
	set_vector(((s_sphere *)((s_lstobjects *)lstobj->next)->object)->center, 2, 0, 4);
	/** LIGHTS **/
	lstlight = new_obj(TYPE_LIGHT, new_default_light(TYPE_AMBIENT, 0.2));
	lstlight->next = new_obj(TYPE_LIGHT, new_default_light(TYPE_POINT, 0.6));
	set_vector(((s_light *)lstlight->next)->vector, 2, 1, 0);
	((s_lstobjects *)lstlight->next)->next = new_obj(TYPE_LIGHT, new_default_light(TYPE_DIRECTIONAL, 0.2));
	set_vector(((s_light *)((s_lstobjects *)lstlight->next)->next)->vector, 1, 4, 4);
	/** RENDERING **/
	i = 0;
	x = -(viewport->width/2);
	while (x < viewport->width/2)
	{
		y = -(viewport->height/2);
		while (y < viewport->height/2)
		{
			t_min_max[0] = 1;
			t_min_max[1] = -1;
			direction = new_vector(x / viewport->width, y /viewport->height, 1);
			color = trace_ray(*obs, *direction, lstobj, t_min_max, lstlight);
			mlx_pixel_put(mlx_ptr, win_ptr, (x + (viewport->width/2)), -(y - (viewport->height/2)), color);
			y++;
		}
		x++;
	}
	/** WINDOW'S LOOP **/
	mlx_loop(mlx_ptr);
}
