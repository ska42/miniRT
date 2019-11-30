/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 03:15:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 23:35:13 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "scene.h"

int			choice_parsing(s_scene **scene, char *line);
void		setup_cameras(s_scene **scene);
void		setup_viewplane(s_scene **scene);
s_scene		*parsing(int fd);
int			open_and_check_error(char *filename, int *fd);

int			parsing_resolution(s_scene **scene, char *line);
int			parsing_ambient_light(s_scene **scene, char *line);
int			parsing_point_light(s_scene **scene, char *line);
int			parsing_directional_light(s_scene **scene, char *line);
int			parsing_camera(s_scene **scene, char *line);

int			parsing_sphere(s_scene **scene, char *line);
int			parsing_plan(s_scene **scene, char *line);
int			parsing_square(s_scene **scene, char *line);
int			parsing_triangle(s_scene **scene, char *line);
int			parsing_cylinder(s_scene **scene, char *line);

#endif
