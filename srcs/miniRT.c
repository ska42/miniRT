/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 08:23:07 by lmartin          ###   ########.fr       */
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
	s_vector		*rota_x;
	s_vector		*rota_y;
	s_vector		*rota_z;
	s_vector		*temp;

	(void)argc;
	(void)argv;
	/**	WINDOW **/
	mlx_ptr = mlx_init();
	viewport = new_canvas(700, 700, 1);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "miniRT");
	/** SPHERES & O & CAM **/
	obs = new_vector(3, 0, 0);
	rota_x = new_vector(0.7071, 0, -0.7071);
	rota_y = new_vector(0, 1, 0);
	rota_z = new_vector(0.7071, 0, 0.7071);
	camera = new_camera(obs, rota_x, rota_y, rota_z);
	lstobj = new_obj(TYPE_SPHERE, new_default_sphere(1, 0xbf3eff));
	set_vector(((s_sphere *)lstobj->object)->center, 0, -1, 3);
	set_shiny((s_sphere *)lstobj->object, 500);
	lstobj->next = new_obj(TYPE_SPHERE, new_default_sphere(1, 0x6400));
	set_vector(((s_sphere *)((s_lstobjects *)lstobj->next)->object)->center, 2, 0, 4);
	set_shiny(((s_sphere *)((s_lstobjects *)lstobj->next)->object), 500);
	((s_lstobjects *)lstobj->next)->next = new_obj(TYPE_SPHERE, new_default_sphere(1, 0x7b68ee));
	set_vector(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object)->center, -2, 0, 4);
	set_shiny(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object), 10);
	/** PLAN **/
	((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->next = new_obj(TYPE_PLAN, new_plan(new_vector(0, -2, 0), new_vector(0, 1, 0), 0xff0000));
	//lstobj = new_obj(TYPE_PLAN, new_plan(new_vector(0, 0, 3), new_vector(0, 1, 1), 0xfffafa));
	/** LIGHTS **/
	lstlight = new_obj(TYPE_LIGHT, new_default_light(TYPE_AMBIENT, 0.2));
	lstlight->next = (s_lstobjects *)new_obj(TYPE_LIGHT, new_default_light(TYPE_POINT, 0.6));
	set_vector(((s_light *)((s_lstobjects *)lstlight->next)->object)->vector, 0, -1, 0);
	((s_lstobjects *)lstlight->next)->next = new_obj(TYPE_LIGHT, new_default_light(TYPE_DIRECTIONAL, 0.2));
	set_vector(((s_light *)((s_lstobjects *)((s_lstobjects *)lstlight->next)->next)->object)->vector, 1, 4, 4);
	/** ON MET TOUT DANS LA SCENE **/
	scene = new_scene(obs, lstobj, lstlight, 0x0);
	/** RENDERING **/
	x = -(viewport->width/2) + 1;
	while ((x + (viewport->width/2) <= viewport->width))
	{
		y = -(viewport->height/2) + 1;
		while (y < viewport->height/2)
		{
			temp = new_vector(x / viewport->width, y / viewport->height, 1);
			direction = multiply_vectors_rotation(*camera->rotation, *temp);
			free(temp);
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
