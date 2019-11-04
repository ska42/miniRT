/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 02:38:22 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/04 02:39:00 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECT_H
# define REFLECT_H

s_vector	*reflect_ray(s_vector v1, s_vector v2);
int			color_with_reflect(s_lstobjects *closest_object, s_scene *scene, s_lightning_vectors *l_vectors, int color);

#endif
