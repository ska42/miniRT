/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:43:38 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/21 00:33:18 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <pthread.h>
#include <sys/time.h>

pthread_mutex_t lock;

typedef struct t_args
{
	char *data;
	s_scene *scene;
	s_vector *obs;
	int x;
	int max;
	int bpp;
	int size_line;
}				s_args;


void			putimage(char *data, int bpp, int size_line, int x, int y, int color)
{
		int	i;

		i = (x * (bpp / 8)) + (y * size_line);
		pthread_mutex_lock(&lock);
		data[i] = color;
		data[++i] = color >> 8;
		data[++i] = color >> 16;
		pthread_mutex_unlock(&lock);
}

void	*thread_function(void *arguments)
{
	char *data;
	s_scene *scene;
	s_vector *obs;
	int x;
	int max;
	int bpp;
	int size_line;
	s_vector		*direction;
	s_vector		*angle;
	int				color;
	int y;
   	s_args *args = (s_args *)arguments;
	data = args->data;
	scene = args->scene;
	obs = args->obs;
	x = args->x;
	max = args->max;
	bpp = args->bpp;
	size_line = args->size_line;
	//printf("x : %i\n", x);
	//printf("max : %i\n", max);
	s_scene *cpy;
	angle = new_vector(((s_camera *)scene->cameras->object)->rotation->x/1 * 180, ((s_camera *)scene->cameras->object)->rotation->y/1 * 180, ((s_camera *)scene->cameras->object)->rotation->z/1 * 180);
	cpy = cpy_scene(scene);
	while (x <= max)
	{
		//printf("ok\n");
			y = -(scene->viewport->height/2);
			while (y <= scene->viewport->height/2)
			{
					//printf("y : %d\n", y);
					direction = new_vector(x * (scene->viewplane->width / scene->viewport->width), y * (scene->viewplane->height / scene->viewport->height), 1);
					rot(direction, angle);
					//printf("direction (%f, %f, %f)\n", direction->x, direction->y, direction->z);
					color = trace_ray(*direction, cpy);
					putimage(data, bpp, size_line, (int)((x + (scene->viewport->width/2))), (int)((-(y - (scene->viewport->height/2)))), color);
					free(direction);
					((s_camera *)cpy->cameras->object)->origin = obs;
					cpy->depth = 3;
					y++;
					//printf("%i : y %i\n", i, y);
			}
		x++;
		//printf("%i : x %i\n", i, x);
	}
	free(cpy);
	//printf("end\n %i\n",i);
	return (NULL);
}


int		main(int argc, char *argv[])
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	int				fd;
	s_scene			*scene;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	s_vector		*obs;
	pthread_t		*threads;
	int				x;
	//int				**all_pipes;
	struct timeval start, stop;
	double secs = 0;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	scene = parsing(fd);
		gettimeofday(&start, NULL);
	if (scene->viewport->height < scene->viewport->width)
		scene->viewplane = new_canvas(scene->viewport->width/scene->viewport->height, 1, 1);
	else
		scene->viewplane = new_canvas(1, scene->viewport->height/scene->viewport->width, 1);
	mlx_ptr = mlx_init();
	mlx_img = mlx_new_image(mlx_ptr, scene->viewport->width, scene->viewport->height);
	win_ptr = mlx_new_window(mlx_ptr, scene->viewport->width, scene->viewport->height, "miniRT");
	data = mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);
	int i;
	int nb_fork;
	nb_fork = 20;
	threads = malloc(sizeof(pthread_t) * nb_fork);
	if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
			obs = ((s_camera *)scene->cameras->object)->origin;
	i = 0;
	s_args *args;
	while (i < nb_fork)
	{
		x = -(scene->viewport->width/2) + 1 + i * (scene->viewport->width) / nb_fork;
		int max;
		max = x + ((scene->viewport->width) / nb_fork) - 1;
		args = malloc(sizeof(s_args));
		args->data = data;
		args->scene = scene;
		args->obs = obs;
		args->x = x;
		args->max = max;
		args->bpp = bpp;
		args->size_line = size_line;
		if (pthread_create(&threads[i], NULL, &thread_function, args)) {
			perror("pthread_create");
			return EXIT_FAILURE;
		}
		i++;
	}
	int size = i;
	i = 0;
	while (i < size)
	{
		if (pthread_join(threads[i], NULL)) {
			perror("pthread_join");
			return EXIT_FAILURE;
    	}
		i++;
	}
	pthread_mutex_destroy(&lock);
	//printf("ended\n");
	i = nb_fork;
	while (--i)
		wait(NULL);
	//data = mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);
	//printf("data %s\n", data);
	//mlx_img = mlx_new_image(mlx_ptr, viewport->width, viewport->height);
	//mlx_ptr2 = mlx_init();
	mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_img, 0, 0);

	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
printf("time taken %fs\n",secs);
	mlx_loop(mlx_ptr);
}

/**
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
	s_lstobjects	*cameras;
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

	mlx_ptr = mlx_init();
	viewport = new_canvas(1000, 700, 1);
	if (viewport->height < viewport->width)
		viewplane = new_canvas(viewport->width/viewport->height, 1, 1);
	else
		viewplane = new_canvas(1, viewport->height/viewport->width, 1);
	mlx_img = mlx_new_image(mlx_ptr, viewport->width, viewport->height);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "miniRT");

	obs = new_vector(-6, 2, -4);
	rota = new_vector(0.001, 0.003, 0);
	camera = new_camera(obs, rota, 70);
	cameras = NULL;
	add_back(&cameras, TYPE_CAMERA, camera);
	lstobj = NULL;
	add_back(&lstobj, TYPE_SPHERE, new_default_sphere(2, 0xbf3eff));
	set_vector(((s_sphere *)lstobj->object)->center, 0, -1, 3);
	set_shiny((s_sphere *)lstobj->object, 500);
	//add_back(&lstobj, TYPE_SPHERE, new_default_sphere(2, 0x6400));
	//set_vector(((s_sphere *)((s_lstobjects *)lstobj->next)->object)->center, 2, 0, 4);
	//set_shiny(((s_sphere *)((s_lstobjects *)lstobj->next)->object), 500);
	//add_back(&lstobj, TYPE_SPHERE, new_default_sphere(1, 0x7b68ee));
	//set_vector(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object)->center, -2, 0, 4);
	//set_shiny(((s_sphere *)((s_lstobjects *)((s_lstobjects *)lstobj->next)->next)->object), 10);

	//add_back(&lstobj, TYPE_PLAN, new_plan(new_vector(0, -2, 0), new_vector(0, 1, 0), 0xff0000));
	//s_plan *plan = new_plan(new_vector(-3, 0, 0), new_vector(1, 0, 0), 0xfffafa);
	//add_back(&lstobj, TYPE_PLAN, plan);

	//add_back(&lstobj, TYPE_SQUARE, new_square(new_vector(0, 3, 5), new_vector(0, 0, 0.5), 1, 0xffff00));
	//lstobj = new_obj(TYPE_PLAN, new_plan(new_vector(0, 0, 3), new_vector(0, 1, 1), 0xfffafa));
	//add_back(&lstobj, TYPE_TRIANGLE, new_triangle(new_vector(-5, 2, 3), new_vector(-2, 0, 4), new_vector(-4, 3, 6), 0xfffafa));
	//s_vector *cylinder_par[2];
	//cylinder_par[0] = new_vector(-5, 0, 5);
	//cylinder_par[1] = new_vector(0.7, 0.5, 0.5);
	//add_back(&lstobj, TYPE_CYLINDER, new_cylinder(cylinder_par, 1, 2, 0xffffffff));

	lstlight = NULL;
	add_back(&lstlight, TYPE_LIGHT, new_default_light(TYPE_AMBIENT, 0.5, 0xffffffff));
	add_back(&lstlight, TYPE_LIGHT, new_default_light(TYPE_POINT, 0.6, 0xffffffff));
	set_vector(((s_light *)((s_lstobjects *)lstlight->next)->object)->vector, 2, 1, 0);
	//add_back(&lstlight, TYPE_LIGHT, new_default_light(TYPE_DIRECTIONAL, 0.2, 0xffffffff));
	//set_vector(((s_light *)((s_lstobjects *)lstlight->next)->object)->vector, 1, 4, 4);
	//set_vector(((s_light *)((s_lstobjects *)((s_lstobjects *)lstlight->next)->next)->object)->vector, 1, 4, 4);

	scene = new_scene(cameras, lstobj, lstlight, 0x0);

	angle = new_vector(rota->x/1 * 180, rota->y/1 * 180, rota->z/1 * 180);
	x = -(viewport->width/2);
	data = mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);
	printf("viewplane : (%f, %f)\n", viewplane->width, viewplane->height);
	printf("viewport : (%f, %f)\n", viewport->width, viewport->height);
	printf("angle (%f, %f, %f)\n", angle->x, angle->y, angle->z);
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
			camera->origin = obs;
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
	mlx_loop(mlx_ptr);
}**/
