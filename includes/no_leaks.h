/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 08:05:59 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/17 01:03:00 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NO_LEAKS_H
# define NO_LEAKS_H

int		free_and_return_minus_one(void *ptr);
int		multiple_free_return(s_vector *ptr[], int size);

#endif
