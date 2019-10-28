/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:40:42 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/28 09:21:55 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>

typedef struct 	t_pos
{
	int		x;
	int		y;
	int		z;
}				s_pos;

typedef struct	t_pos2d
{
	int		x;
	int		y;
}				s_pos2d;

typedef	struct	t_canvas
{
	int		width;
	int		height;
	int		distance;
}				s_canvas;

typedef	struct	t_sphere
{
	int		size;
	int		color;
	s_pos	*position;
}				s_sphere;

s_pos			*create_pos(int x, int y, int z)
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

s_sphere		*create_sphere(int s, int color)
{
	s_sphere	*sphere;

	sphere = malloc(sizeof(s_sphere));
	sphere->size = s;
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

int		dot_product(s_pos pos1, s_pos pos2)
{
	return (pos1.x * pos2.x + pos1.y * pos2.y + pos1.z * pos2.z);
}

double	ft_sqrt(int x)
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

s_pos2d		*intersect(s_pos origin, s_pos pixel, s_sphere sphere)
{
	s_pos	*difference;
	int		k[3];
	int		discriminant;

	difference = create_pos(origin.x - pixel.x, origin.y - pixel.y, origin.z - pixel.z);
	k[0] = dot_product(pixel, pixel);
	k[1] = 2 * dot_product(*difference, pixel);
	k[2] = dot_product(*difference, *difference) - (sphere.size/2 * sphere.size/2);

	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
		return (NULL);
	return (create_pos2d((-k[1] + ft_sqrt(discriminant)) / (2 * k[0]), (-k[1] - ft_sqrt(discriminant)) / (2 * k[0])));
}

int				main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	s_pos		*obs_pos;
	s_pos		*checking_pixel;
	s_pos2d		*pos2d;
	s_canvas	*viewport;
	s_sphere	*sphere;
	int			x;
	int			y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 480, 480, "Hello W0rld");
	/* TEST */
	obs_pos = create_pos(0, 0, 0);
	viewport = create_canvas(480, 480, 0);
	sphere = create_sphere(10, 0xffc0cb);
	set_pos(sphere->position, 200, 200, 1200);
	x = 0;
	while (x < viewport->width)
	{
		y = 0;
		while (y < viewport->height)
		{
			checking_pixel = create_pos(x, y, viewport->distance);
			pos2d = intersect(*obs_pos, *checking_pixel, *sphere);
			if (!pos2d)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, sphere->color);
			free(pos2d);
			pos2d = NULL;
			y++;
		}
		x++;
	}
	/* LOOP 4 SCREEN */
	mlx_loop(mlx_ptr);
}
