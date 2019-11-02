/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:30:36 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/02 09:34:31 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTNING_H
# define LIGHTNING_H

#include <stdlib.h>
#include "lstobjects.h"
#include "vector.h"
#include "light.h"

float	calcul_reflection(s_lightning_vectors *l_vectors, s_light *light, float length_v, s_vector *vec_l);
float	compute_special_lights(s_lightning_vectors *l_vectors, s_light *light);
float	compute_lightning(s_lightning_vectors *l_vectors, s_lstobjects *lights);

#endif
