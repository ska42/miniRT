/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 08:03:15 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/17 01:03:13 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		free_and_return_minus_one(void *ptr)
{
	free(ptr);
	return (-1);
}

int		multiple_free_return(s_vector *ptr[], int size)
{
	while (size--)
		free(ptr[size]);
	return (-1);
}
