/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:06:29 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/30 22:37:42 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct t_args
{
	char			*data;
	s_scene			*scene;
	int				x;
	int				bpp;
	int				size_line;
	pthread_mutex_t *lock;
}				s_args;

void	put_pixel(s_args *args, int y, int color);
void	*thread_function(void *arguments);
s_args	*new_s_args(s_mlx *my_mlx, int i, pthread_mutex_t *lock);
void	create_image(s_mlx	*my_mlx);

#endif
