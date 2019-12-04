/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 03:15:02 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/04 16:54:22 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "scene.h"

int			choice_parsing(t_scene **scene, char *line);
void		setup_cameras(t_scene **scene);
void		setup_viewplane(t_scene **scene);
t_scene		*parsing(int fd);
int			open_and_check_error(char *filename, int *fd);

int			parsing_resolution(t_scene **scene, char *line);
int			parsing_ambient_light(t_scene **scene, char *line);
int			parsing_point_light(t_scene **scene, char *line);
int			parsing_directional_light(t_scene **scene, char *line);
int			parsing_camera(t_scene **scene, char *line);

int			parsing_sphere(t_scene **scene, char *line);
int			parsing_plan(t_scene **scene, char *line);
int			parsing_square(t_scene **scene, char *line);
int			parsing_triangle(t_scene **scene, char *line);
int			parsing_cylinder(t_scene **scene, char *line);

#endif
