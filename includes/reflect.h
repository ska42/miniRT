/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 02:38:22 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:23 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECT_H
# define REFLECT_H

t_vector	*reflect_ray(t_vector v1, t_vector v2);
int			color_with_reflect(t_lstobjects *closest_object, t_scene *scene,
t_lightning_vectors *l_vectors, int color);

#endif
