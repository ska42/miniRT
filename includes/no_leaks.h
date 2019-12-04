/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 08:05:59 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/23 22:38:19 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NO_LEAKS_H
# define NO_LEAKS_H

int		free_and_return_minus_one(void *ptr);
int		multiple_free_return(t_vector *ptr[], int size);
int		free_l_vectors(t_lightning_vectors *l_vectors);

#endif
