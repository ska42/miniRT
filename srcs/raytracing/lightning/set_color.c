/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:39:39 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:55:17 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_color_ambient(t_vector *color[4], float *intensity,
t_lstobjects *lights)
{
	*intensity += ((t_light *)lights->object)->intensity;
	color[1] = cpy_vector(((t_light *)lights->object)->color);
	color[0] = new_vector(color[2]->x + ((color[1]->x + color[3]->x) *
(*intensity)),
color[2]->y + ((color[1]->y + color[3]->y) * (*intensity)),
color[2]->z + ((color[1]->z + color[3]->z) * (*intensity)));
	free(color[1]);
	free(color[2]);
	rearrange_rgb(color[0]);
}

void	set_color_special_lights(float *intensity, t_l_o_v_s *lovs,
t_lstobjects *objects, t_lstobjects *lights)
{
	(*intensity) += compute_special_lights(lovs->l_vectors, (t_light *)
lights->object, lovs->scene, objects);
	lovs->color[1] = new_vector(((((t_light *)lights->object)->color->x *
((*intensity) / lovs->scene->total_intensity)) - lovs->color[3]->x),
((((t_light *)lights->object)->color->y * ((*intensity) /
lovs->scene->total_intensity)) - lovs->color[3]->y),
((((t_light *)lights->object)->color->z * ((*intensity) /
lovs->scene->total_intensity)) - lovs->color[3]->z));
	lovs->color[0] = new_vector(lovs->color[2]->x + (lovs->color[3]->x +
(lovs->color[1]->x)),
lovs->color[2]->y + (lovs->color[3]->y + (lovs->color[1]->y)),
lovs->color[2]->z + (lovs->color[3]->z + (lovs->color[1]->z)));
	free(lovs->color[1]);
	free(lovs->color[2]);
	rearrange_rgb(lovs->color[0]);
}
