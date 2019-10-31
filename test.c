/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:40:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/31 13:59:52 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct 	t_pos
{
	float		x;
	float		y;
	float		z;
}				s_pos;

typedef struct	t_pos2d
{
	float		x;
	float		y;
}				s_pos2d;

typedef	struct	t_canvas
{
	float	width;
	float	height;
	float	distance;
}				s_canvas;

typedef	struct	t_sphere
{
	float	radius;
	int		color;
	s_pos	*position;
}				s_sphere;

typedef struct	t_light
{
	int		type;
	float	intensity;
	s_pos	*position;
}				s_light;

typedef struct	t_lstobject
{
	int		type;
	void	*object;
	void	*next;
}				s_lstobject;

s_lstobject		*create_obj(int t, void *o)
{
	s_lstobject *obj;

	obj = malloc(sizeof(s_lstobject));
	obj->type	= t;
	obj->object = o;
	obj->next	= NULL;
	return (obj);
}

s_pos			*create_pos(float x, float y, float z)
{
	s_pos	*position;

	position = malloc(sizeof(s_pos));
	position->x = x;
	position->y = y;
	position->z = z;
	return (position);
}

s_pos2d			*create_pos2d(int x, int y)
{
	s_pos2d	*position;

	position = malloc(sizeof(s_pos2d));
	position->x = x;
	position->y = y;
	return (position);
}

void			set_pos(s_pos *position, float x, float y, float z)
{
	position->x = x;
	position->y = y;
	position->z = z;
}

s_light			*create_light(int t, float i)
{
	s_light		*light;

	light = malloc(sizeof(s_light));
	light->type = t;
	light->intensity = i;
	light->position = create_pos(0, 0, 0);
	return (light);
}

s_sphere		*create_sphere(int r, int color)
{
	s_sphere	*sphere;

	sphere = malloc(sizeof(s_sphere));
	sphere->radius = r;
	sphere->color = color;
	sphere->position = create_pos(0, 0, 0);
	return (sphere);
}

s_canvas		*create_canvas(int w, int h, int d)
{
	s_canvas	*canvas;

	canvas = malloc(sizeof(s_canvas));
	canvas->width = w;
	canvas->height = h;
	canvas->distance = d;
	return (canvas);
}

float	dot_product(s_pos pos1, s_pos pos2)
{
	return (pos1.x * pos2.x + pos1.y * pos2.y + pos1.z * pos2.z);
}

float	ft_sqrt(const float x)
{
	int	i;
	float j;

	j = x;
	i = (1 << 29) + (i >> 1) - (1 << 22);
	j = 0.5f * (j + x/j);
	j = 0.5f * (j + x/j);
	return (j);
}

float	intersect(s_pos origin, s_pos direction, void *s)
{
	s_pos	*difference;
	float	k[3];
	float	discriminant;
	s_sphere sphere;
	float t1;
	float t2;

	sphere = *(s_sphere *)(s);
	//printf("sphere pos x : %f\n", sphere.position->x);
	//printf("sphere pos y : %f\n", sphere.position->y);
	//printf("sphere pos z : %f\n", sphere.position->z);
	//printf("direction pos x : %f\n", direction.x);
	//printf("direction pos y : %f\n", direction.y);
	//printf("direction pos z : %f\n", direction.z);
	difference = create_pos(origin.x - sphere.position->x, origin.y - sphere.position->y, origin.z - sphere.position->z);
	//printf("difference pos x : %f\n", difference->x);
	//printf("difference pos y : %f\n", difference->y);
	//printf("difference pos z : %f\n", difference->z);
	k[0] = dot_product(direction, direction);
	k[1] = 2 * dot_product(*difference, direction);
	k[2] = dot_product(*difference, *difference) - (sphere.radius * sphere.radius);
	//printf("k[0] : %f\n", k[0]);
	//printf("k[1] : %f\n", k[1]);
	//printf("k[2] : %f\n", k[2]);
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
		return (0);
	//printf("sqrt(discriminant) : %d\n", ft_sqrt(discriminant));
	t1 = (- k[1] + ft_sqrt(discriminant)) / (2 * k[0]);
	t2 = (- k[1] - ft_sqrt(discriminant)) / (2 * k[0]);
	free(difference);
	if (t1 < t2)
		return (t1);
	return (t2);
}

int				main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	s_pos		*obs_pos;
	s_pos		*direction;
	s_canvas	*viewport;
	s_sphere	*sphere;
	s_lstobject *lstobj;
	s_lstobject *begin;
	s_light		*light;
	int			x;
	int			y;
	int			printed;
	float		n_dot_l;
	float		intensity;
	float		ts;
	int			color;

	mlx_ptr = mlx_init();
	viewport = create_canvas(500, 500, 1);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "Hello W0rld");
	/* TEST */
	obs_pos = create_pos(0, 0, 0);
	sphere = create_sphere(10, 0xbf3eff);
	set_pos(sphere->position, -75, -75, 200);
	lstobj = create_obj(0, sphere);
	begin = lstobj;
	sphere = create_sphere(25, 0x6400);
	set_pos(sphere->position, 25, 25, 75);
	light = create_light(0, 0.2);
	set_pos(light->position, 0, 0, 1);
	lstobj->next = create_obj(0, sphere);
	x = -viewport->width/2;
	while (x < viewport->width/2)
	{
		y = -viewport->height/2;
		while (y < viewport->height/2)
		{
			printed = 0;
			while (lstobj)
			{
				direction = create_pos(x / viewport->width, y / viewport->height, 1);
				ts = intersect(*obs_pos, *direction, lstobj->object);
				if (ts)
				{
					s_pos	*point;
					s_pos	*normal;
					point = create_pos(obs_pos->x + ts * direction->x, obs_pos->y + ts * direction->y, obs_pos->z + ts * direction->z);
					normal = create_pos(point->x - ((s_sphere *)(lstobj->object))->position->x, point->y - ((s_sphere *)lstobj->object)->position->y, point->z - ((s_sphere *)lstobj->object)->position->y);
					set_pos(normal, 1/ft_sqrt(dot_product(*normal, *normal)) * normal->x, 1/ft_sqrt(dot_product(*normal, *normal)) * normal->y, 1/ft_sqrt(dot_product(*normal, *normal)) * normal->z);
					n_dot_l = dot_product(*normal, *light->position);
					//printf("n_dot_l %f\n", n_dot_l);
					intensity = 0;
					if (n_dot_l > 0)
						intensity += light->intensity * n_dot_l / (ft_sqrt(dot_product(*light->position, *light->position)) * 1);
					printf("intensity : %f\n", intensity);
					color = ((s_sphere *)(lstobj->object))->color + ((s_sphere *)(lstobj->object))->color * intensity;
					printed = 1;
					mlx_pixel_put(mlx_ptr, win_ptr, (x + viewport->width/2), (y + viewport->height/2), color);
				}
				free(direction);
				direction = NULL;
				lstobj = lstobj->next;
			}
			lstobj = begin;
			if (!printed)
			{
				if (x == 0 || y == 0)
					mlx_pixel_put(mlx_ptr, win_ptr, (x + viewport->width/2), y + (viewport->height/2), 0xfffafa);
				else
					mlx_pixel_put(mlx_ptr, win_ptr, (x + viewport->width/2), y + (viewport->height/2), 0x0);
			}
			y++;
		}
		x++;
	}
	/* LOOP 4 SCREEN */
	mlx_loop(mlx_ptr);
}
