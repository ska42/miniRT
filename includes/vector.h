/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:02:22 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:43:58 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_lightning_vectors
{
	t_vector	*point;
	t_vector	*normal;
	t_vector	*view;
	float		shiny;
}				t_lightning_vectors;

/*
** Calculation
*/
float			length_vectors(t_vector v);
float			distance_points(t_vector p1, t_vector p2);
float			product_vectors(t_vector v1, t_vector v2);
t_vector		*cross(t_vector u, t_vector v);
t_vector		*product_scalar(t_vector u, t_vector v);
t_vector		*add_vectors(t_vector v1, t_vector v2);
t_vector		*subtract_vectors(t_vector v1, t_vector v2);
t_vector		*multiply_vectors_rotation(t_vector r, t_vector v2);
t_vector		*multiply_vectors(float k, t_vector v2);

/*
** Color
*/
t_vector		*color_to_rgb(unsigned int color);
int				rgb_to_color(t_vector *rgb);
void			rearrange_rgb(t_vector *color);

/*
** Vector
*/
t_vector		*new_vector(float x, float y, float z);
t_vector		*cpy_vector(t_vector *vector);
int				is_equal(t_vector *a, t_vector *b);

#endif
