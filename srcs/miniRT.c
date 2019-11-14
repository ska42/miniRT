/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/14 04:20:47 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void			putimage(char *data, int bpp, int size_line, int x, int y, int color)
{
		int	i;

		i = (x * (bpp / 8)) + (y * size_line);
		data[i] = color;
		data[++i] = color >> 8;
		data[++i] = color >> 16;
}

int		main(int	argc, char *argv[])
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	s_canvas		*viewport;
	s_canvas		*viewplane;
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
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;

	(void)argc;
	(void)argv;
	/**	WINDOW **/
	mlx_ptr = mlx_init();
	viewport = new_canvas(1000, 700, 1);
	if (viewport->height < viewport->width)
		viewplane = new_canvas(viewport->width/viewport->height, 1, 1);
	else
		viewplane = new_canvas(1, viewport->height/viewport->width, 1);
	mlx_img = mlx_new_image(mlx_ptr, viewport->width, viewport->height);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "miniRT");
	/** SPHERES & O & CAM **/
	obs = new_vector(-6, 2, -4);
	rota = new_vector(0.001, 0.003, 0);
	camera = new_camera(obs, rota);
	lstobj = NULL;
	add_back(&lstobj, TYPE_SPHERE, new_default_sphere(1, 0xbf3eff));
	set_vector(((s_sphere *)lstobj->object)->center, 0, -1, 3);
	set_shiny((s_sphere *)lstobj->object, 500);
	add_back(&lstobj, TYPE_SPHERE, new_default_sphere(2, 0x6400));
	set_vector(((s_sphere *)((s_lstobjects *)lstobj->next)->object)->center, 2, 0, 4);
	set_shiny(((s_sphere *)((s_lstobjects *)lstobj->next)->object), 500);
	add_back(&lstobj, TYPE_SPHERE, new_default_sphere(1, 0x7b68ee));
	set_vector(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object)->center, -2, 0, 4);
	set_shiny(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object), 10);
	/** PLAN **/
	add_back(&lstobj, TYPE_PLAN, new_plan(new_vector(0, -2, 0), new_vector(0, 1, 0), 0xff0000));
	//s_plan *plan = new_plan(new_vector(-3, 0, 0), new_vector(1, 0, 0), 0xfffafa);
	//add_back(&lstobj, TYPE_PLAN, plan);
	/** SQUARE **/
	add_back(&lstobj, TYPE_SQUARE, new_square(new_vector(0, 3, 5), new_vector(0, 0, 0.5), 1, 0xffff00));
	//lstobj = new_obj(TYPE_PLAN, new_plan(new_vector(0, 0, 3), new_vector(0, 1, 1), 0xfffafa));
	add_back(&lstobj, TYPE_TRIANGLE, new_triangle(new_vector(-5, 2, 3), new_vector(-2, 0, 4), new_vector(-4, 3, 6), 0xfffafa));
	add_back(&lstobj, TYPE_CYLINDER, new_cylinder(new_vector(-3, 2, 10), new_vector(1, 1, 0), 1, 2));
	/** LIGHTS **/
	lstlight = NULL;
	add_back(&lstlight, TYPE_LIGHT, new_default_light(TYPE_AMBIENT, 0.5));
	add_back(&lstlight, TYPE_LIGHT, new_default_light(TYPE_POINT, 0.6));
	set_vector(((s_light *)((s_lstobjects *)lstlight->next)->object)->vector, 2, 1, 0);
	add_back(&lstlight, TYPE_LIGHT, new_default_light(TYPE_DIRECTIONAL, 0.2));
	//set_vector(((s_light *)((s_lstobjects *)lstlight->next)->object)->vector, 1, 4, 4);
	set_vector(((s_light *)((s_lstobjects *)((s_lstobjects *)lstlight->next)->next)->object)->vector, 1, 4, 4);
	/** ON MET TOUT DANS LA SCENE **/
	scene = new_scene(obs, lstobj, lstlight, 0x0);
	/** RENDERING **/
	angle = new_vector(rota->x/1 * 180, rota->y/1 * 180, rota->z/1 * 180);
	x = -(viewport->width/2);
	data = mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);
	while ((x + (viewport->width/2) <= viewport->width))
	{
		y = -(viewport->height/2);
		while (y <= viewport->height/2)
		{
			//printf("y : %d\n", y);
			direction = new_vector(x * (viewplane->width / viewport->width), y * (viewplane->height / viewport->height), 1);
			rot(direction, angle);
			//printf("direction (%f, %f, %f)\n", direction->x, direction->y, direction->z);
			color = trace_ray(*direction, scene);
			if (color != scene->background_color)
			{
				putimage(data, bpp, size_line, (int)((x + (viewport->width/2))), (int)((-(y - (viewport->height/2)))), color);
				//printf("ko\n");
				//mlx_pixel_put(mlx_ptr, win_ptr, (int)(x + (viewport->width/2)), (int)(-(y - (viewport->height/2))), (int)color);
			}
			free(direction);
			scene->origin = obs;
			scene->depth = 3;
			y++;
		}
		x++;
	}
	//data = mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);
	//printf("data %s\n", data);
	//mlx_img = mlx_new_image(mlx_ptr, viewport->width, viewport->height);
	//mlx_ptr2 = mlx_init();
	mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_img, 0, 0);
	/** WINDOW'S LOOP **/
	mlx_loop(mlx_ptr);
}
