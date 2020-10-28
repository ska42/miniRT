/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:57:29 by lmartin           #+#    #+#             */
/*   Updated: 2020/10/28 14:27:48 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Change pixel color by changing (char *data)
** (R) data[i]
** (G) data[i + 1]
** (B) data[i + 2]
*/

void	put_pixel(t_args *args, int y, int color)
{
	int	i;

	i = ((args->x + (args->scene->viewport->width / 2)) *
(args->bpp / 8)) + (y * args->size_line);
	pthread_mutex_lock(args->lock);
	args->data[i] = color;
	args->data[++i] = color >> 8;
	args->data[++i] = color >> 16;
	pthread_mutex_unlock(args->lock);
}

/*
** Function for each thread (1 thread == 1 column)
*/

void	*thread_function(void *arguments)
{
	t_vector		*obs;
	t_vector		*d;
	int				c;
	int				y;
	t_args			*args;

	args = (t_args *)arguments;
	if (!(t_camera *)args->scene->cameras)
		return (free_cpy_scene(args->scene) ? NULL : NULL);
	obs = ((t_camera *)args->scene->cameras->object)->origin;
	y = -(args->scene->viewport->height / 2);
	while (++y <= args->scene->viewport->height / 2)
	{
		d = new_vector(
args->x * (args->scene->viewplane->width / args->scene->viewport->width),
y * (args->scene->viewplane->height / args->scene->viewport->height), 1);
		rot(d, ((t_camera *)args->scene->cameras->object)->rotation);
		c = trace_ray(*d, args->scene);
		put_pixel(args, ((-(y - (args->scene->viewport->height / 2)))), c);
		free(d);
		((t_camera *)args->scene->cameras->object)->origin = obs;
		args->scene->depth = 3;
	}
	return (free_cpy_scene(args->scene) ? NULL : NULL);
}

/*
** Init a new t_args with all arguments for thread_function
*/

t_args	*new_s_args(t_mlx *my_mlx, int i, pthread_mutex_t *lock)
{
	t_args			*args;

	if (!(args = malloc(sizeof(t_args))))
		print_error_and_exit(-7);
	args->data = my_mlx->data;
	args->scene = cpy_scene(my_mlx->scene);
	args->x = -(my_mlx->scene->viewport->width / 2) + i;
	args->bpp = my_mlx->bpp;
	args->size_line = my_mlx->size_line;
	args->lock = lock;
	return (args);
}

/*
** Create a new image charging each column by a thread
*/

void	create_image(t_mlx *my_mlx)
{
	int				i;
	t_args			*args;
	pthread_t		*threads;
	pthread_mutex_t lock;

	if (!(threads = malloc(sizeof(pthread_t) * my_mlx->scene->viewport->width)))
		print_error_and_exit(-7);
	if (pthread_mutex_init(&lock, NULL) != 0)
		pthread_error(-9);
	i = -1;
	while (++i < my_mlx->scene->viewport->width)
	{
		args = new_s_args(my_mlx, i, &lock);
		if (pthread_create(&threads[i], NULL, &thread_function, args))
			pthread_error(-10);
	}
	while (i--)
		if (pthread_join(threads[i], NULL))
			pthread_error(-11);
	pthread_mutex_destroy(&lock);
	i = my_mlx->scene->viewport->width;
	while (--i)
		wait(NULL);
}
