/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:40:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/29 02:04:34 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct 	t_pos
{
	double		x;
	double		y;
	double		z;
}				s_pos;

typedef struct	t_pos2d
{
	int		x;
	int		y;
}				s_pos2d;

typedef	struct	t_canvas
{
	double	width;
	double	height;
	double	distance;
}				s_canvas;

typedef	struct	t_sphere
{
	int		radius;
	int		color;
	s_pos	*position;
}				s_sphere;

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

s_pos			*create_pos(double x, double y, double z)
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

void			set_pos(s_pos *position, int x, int y, int z)
{
	position->x = x;
	position->y = y;
	position->z = z;
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

double	dot_product(s_pos pos1, s_pos pos2)
{
	return (pos1.x * pos2.x + pos1.y * pos2.y + pos1.z * pos2.z);
}

int		ft_sqrt(int x)
{
	int i;
	int result;

    if (x == 0 || x == 1)
    	return (x);
    i = 1;
	result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return (i - 1);
}

s_pos2d		*intersect(s_pos origin, s_pos pixel, void *s)
{
	s_pos	*difference;
	double	k[3];
	double	discriminant;
	s_sphere sphere;
	s_pos2d	*ret;

	sphere = *(s_sphere *)(s);
	//printf("sphere pos x : %f\n", sphere.position->x);
	//printf("sphere pos y : %f\n", sphere.position->y);
	//printf("sphere pos z : %f\n", sphere.position->z);
	//printf("pixel pos x : %f\n", pixel.x);
	//printf("pixel pos y : %f\n", pixel.y);
	//printf("pixel pos z : %f\n", pixel.z);
	difference = create_pos(origin.x - sphere.position->x, origin.y - sphere.position->y, origin.z - sphere.position->z);
	//printf("difference pos x : %f\n", difference->x);
	//printf("difference pos y : %f\n", difference->y);
	//printf("difference pos z : %f\n", difference->z);
	k[0] = dot_product(pixel, pixel);
	k[1] = 2 * dot_product(*difference, pixel);
	k[2] = dot_product(*difference, *difference) - (sphere.radius * sphere.radius);
	//printf("k[0] : %f\n", k[0]);
	//printf("k[1] : %f\n", k[1]);
	//printf("k[2] : %f\n", k[2]);
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	//printf("discriminant : %f\n", discriminant);
	if (discriminant < 0)
		return (NULL);
	//printf("sqrt(discriminant) : %d\n", ft_sqrt(discriminant));
	ret = create_pos2d((-k[1] + ft_sqrt(discriminant)) / (2 * k[0]), (-k[1] - ft_sqrt(discriminant)) / (2 * k[0]));
	free(difference);
	return (ret);
}

int				main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	s_pos		*obs_pos;
	s_pos		*pixel;
	s_pos2d		*pos2d;
	s_canvas	*viewport;
	s_sphere	*sphere;
	s_lstobject *lstobj;
	s_lstobject *begin;
	int			x;
	int			y;
	int			printed;

	mlx_ptr = mlx_init();
	viewport = create_canvas(500, 500, 1);
	win_ptr = mlx_new_window(mlx_ptr, viewport->width, viewport->height, "Hello W0rld");
	/* TEST */
	obs_pos = create_pos(0, 0, 0);
	sphere = create_sphere(10, 0xff00);
	set_pos(sphere->position, -75, -75, 200);
	lstobj = create_obj(0, sphere);
	begin = lstobj;
	sphere = create_sphere(25, 0x87ceff);
	set_pos(sphere->position, 75, 75, 200);
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
				pixel = create_pos(x / viewport->width, y / viewport->height, viewport->distance);
				pos2d = intersect(*obs_pos, *pixel, lstobj->object);
				if (pos2d)
				{
					printed = 1;
					mlx_pixel_put(mlx_ptr, win_ptr, x + viewport->width/2, y + viewport->height/2, ((s_sphere *)(lstobj->object))->color);
				}
				free(pos2d);
				pos2d = NULL;
				free(pixel);
				pixel = NULL;
				lstobj = lstobj->next;
			}
			if (!printed)
				mlx_pixel_put(mlx_ptr, win_ptr, x + viewport->width/2, y + viewport->height/2, 0x0);
			lstobj = begin;
			y++;
		}
		x++;
	}
	/* LOOP 4 SCREEN */
	mlx_loop(mlx_ptr);
}
