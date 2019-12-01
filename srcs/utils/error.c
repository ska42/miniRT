/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:41:32 by lmartin           #+#    #+#             */
/*   Updated: 2019/12/01 01:03:37 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pthread_error(int nb_err)
{
	if (nb_err == -9)
		write(STDERR_FILENO, "Error: mutex init failed\n", 25);
	if (nb_err == -10)
		write(STDERR_FILENO, "Error: pthread create failed\n", 29);
	if (nb_err == -11)
		write(STDERR_FILENO, "Error: pthread join failed\n", 27);
	exit(nb_err);
}

void	print_error_and_exit(int nb_err)
{
	if (nb_err == -1)
		write(STDERR_FILENO, "Error: No such file or directory\n", 33);
	if (nb_err == -2)
		write(STDERR_FILENO, "Error: Extension needed\n", 24);
	if (nb_err == -3)
		write(STDERR_FILENO, "Error: Invalid extension\n", 25);
	if (nb_err == -4)
		write(STDERR_FILENO, "Error: Invalid scene description\n", 33);
	if (nb_err == -5)
		write(STDERR_FILENO, "Error: Resolution not specified\n", 32);
	if (nb_err == -6)
		write(STDERR_FILENO, "Error: Cannot create a window with value zero\n",
46);
	if (nb_err == -7)
		write(STDERR_FILENO, "Error: Allocation problem (missing memory ?)\n",
45);
	if (nb_err == -8)
		write(STDERR_FILENO, "Error: Cannot create/Trunc/Write in file .bmp\n",
46);
	if (nb_err == -9)
		write(STDERR_FILENO, "Error: Wrong number of arguments\n", 31);
	if (nb_err == -10)
		write(STDERR_FILENO, "Error: Error with second argument\n", 32);
	exit(nb_err);
}
