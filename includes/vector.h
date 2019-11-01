/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:02:22 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/01 06:46:28 by lmartin          ###   ########.fr       */
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

/**	CALCULATION **/
float			length_vectors(s_vector v);
float			product_vectors(s_vector v1, s_vector v2);
s_vector		*add_vectors(s_vector v1, s_vector v2);
s_vector		*subtract_vectors(s_vector v1, s_vector v2);
s_vector		*multiply_vectors(float k, s_vector v2);

/** COLOR **/
s_vector *color_to_rgb(unsigned int color);

/** VECTOR **/
void			set_vector(s_vector *vector, float x, float y, float z);
s_vector		*new_vector(float x, float y, float z);

#endif
