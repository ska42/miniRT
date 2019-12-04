/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 08:03:15 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/24 02:10:03 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		free_and_return_minus_one(void *ptr)
{
	free(ptr);
	return (-1);
}

int		multiple_free_return(t_vector *ptr[], int size)
{
	while (size--)
		free(ptr[size]);
	return (-1);
}

int		free_l_vectors(t_lightning_vectors *l_vectors)
{
	free(l_vectors->point);
	free(l_vectors->normal);
	free(l_vectors->view);
	free(l_vectors);
	return (0);
}
