/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 03:15:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/16 07:46:52 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "scene.h"

int		parsing_resolution(s_scene **scene, char *line);
int		parsing_ambient_light(s_scene **scene, char *line);
int		parsing_point_light(s_scene **scene, char *line);
int		parsing_directional_light(s_scene **scene, char *line);
int		parsing_camera(s_scene **scene, char *line);

int		parsing_sphere(s_scene **scene, char *line);
int		parsing_plan(s_scene **scene, char *line);
int		parsing_square(s_scene **scene, char *line);
int		parsing_triangle(s_scene **scene, char *line);
int		parsing_cylinder(s_scene **scene, char *line);

#endif
