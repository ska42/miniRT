/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:41:32 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/24 02:10:45 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
		write(STDERR_FILENO, "Error: Cannot create a window with value zero\n", 46);
	if (nb_err == -7)
		write(STDERR_FILENO, "Error: Allocation problem (missing memory ?)\n", 45);
	exit(nb_err);
}
