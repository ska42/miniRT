/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 11:06:01 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		main(int	argc, char *argv[])
{
	void			*mlx_ptr;
	void			*win_ptr;
	s_canvas		*viewport;
	s_vector		*obs;
	s_camera		*camera;
	s_vector		*direction;
	s_lstobjects	*lstobj;
	s_lstobjects	*lstlight;
	s_scene			*scene;
	int				color;
	int				x;
	int				y;
	s_vector		*rota;
	s_vector		*angle;

	(void)argc;
	(void)argv;
	/**	WINDOW **/
	mlx_ptr = mlx_init();
	viewport = new_canvas(700, 700, 1);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "miniRT");
	/** SPHERES & O & CAM **/
	obs = new_vector(-2, 2, -5);
	rota = new_vector(0.001, 0.001, 0);
	camera = new_camera(obs, rota);
	lstobj = NULL;
	add_back(&lstobj, TYPE_SPHERE, new_default_sphere(1, 0xbf3eff));
	set_vector(((s_sphere *)lstobj->object)->center, 0, -1, 3);
	set_shiny((s_sphere *)lstobj->object, 500);
	add_back(&lstobj, TYPE_SPHERE, new_default_sphere(1, 0x6400));
	set_vector(((s_sphere *)((s_lstobjects *)lstobj->next)->object)->center, 2, 0, 4);
	set_shiny(((s_sphere *)((s_lstobjects *)lstobj->next)->object), 500);
	add_back(&lstobj, TYPE_SPHERE, new_default_sphere(1, 0x7b68ee));
	set_vector(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object)->center, -2, 0, 4);
	set_shiny(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object), 10);
	/** PLAN **/
	add_back(&lstobj, TYPE_PLAN, new_plan(new_vector(0, -2, 0), new_vector(0, 1, 0), 0xff0000));
	//add_back(&lstobj, TYPE_PLAN, new_plan(new_vector(10, 0, 10), new_vector(1, 0, 0), 0xfffafa));
	//lstobj = new_obj(TYPE_PLAN, new_plan(new_vector(0, 0, 3), new_vector(0, 1, 1), 0xfffafa));
	/** LIGHTS **/
	lstlight = new_obj(TYPE_LIGHT, new_default_light(TYPE_AMBIENT, 0.2));
	lstlight->next = (s_lstobjects *)new_obj(TYPE_LIGHT, new_default_light(TYPE_POINT, 0.6));
	set_vector(((s_light *)((s_lstobjects *)lstlight->next)->object)->vector, 0, 5, -3);
	((s_lstobjects *)lstlight->next)->next = new_obj(TYPE_LIGHT, new_default_light(TYPE_DIRECTIONAL, 0.2));
	set_vector(((s_light *)((s_lstobjects *)((s_lstobjects *)lstlight->next)->next)->object)->vector, 1, 4, 4);
	/** ON MET TOUT DANS LA SCENE **/
	scene = new_scene(obs, lstobj, lstlight, 0x0);
	/** RENDERING **/
	angle = new_vector(rota->x/1 * 180, rota->y/1 * 180, rota->z/1 * 180);
	x = -(viewport->width/2) + 1;
	while ((x + (viewport->width/2) <= viewport->width))
	{
		y = -(viewport->height/2) + 1;
		while (y < viewport->height/2)
		{
			direction = new_vector(x / viewport->width, y / viewport->height, 1);
			rot(direction, angle);
			color = trace_ray(*direction, scene);
			if (color != scene->background_color)
				mlx_pixel_put(mlx_ptr, win_ptr, (int)(x + (viewport->width/2)), (int)(-(y - (viewport->height/2))), (int)color);
			free(direction);
			scene->origin = obs;
			scene->depth = 3;
			y++;
		}
		x++;
	}
	/** WINDOW'S LOOP **/
	mlx_loop(mlx_ptr);
}
