/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:02:22 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 05:57:46 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct 	t_vector
{
	float		x;
	float		y;
	float		z;
}				s_vector;

typedef struct	t_lightning_vectors
{
	s_vector	*point;
	s_vector	*normal;
	s_vector	*view;
	float		shiny;
}				s_lightning_vectors;

/**	CALCULATION **/
float			length_vectors(s_vector v);
float			distance_points(s_vector p1, s_vector p2);
float			product_vectors(s_vector v1, s_vector v2);
s_vector		*cross(s_vector u, s_vector v);
s_vector		*product_scalar(s_vector u, s_vector v);
s_vector		*add_vectors(s_vector v1, s_vector v2);
s_vector		*subtract_vectors(s_vector v1, s_vector v2);
s_vector		*multiply_vectors_rotation(s_vector r, s_vector v2);
s_vector		*multiply_vectors(float k, s_vector v2);

/** COLOR **/
s_vector		*color_to_rgb(unsigned int color);
int				rgb_to_color(s_vector *rgb);
void 			rearrange_rgb(s_vector *color);

/** VECTOR **/
s_vector		*new_vector(float x, float y, float z);
s_vector		*cpy_vector(s_vector *vector);
int				is_equal(s_vector *a, s_vector *b);

#endif
