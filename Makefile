# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 02:42:41 by lmartin           #+#    #+#              #
#    Updated: 2019/10/29 05:43:17 by lmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(DIR_HEADERS) = ./includes/

$(NAME) = miniRT

$(LIBMLX) = libmlx

$(DYLIB) = $(LIBMLX).dylib

all:
		make -C ./minilibx_mms_20191025_beta/
		make -C ./minilibx_opengl_20191021/

bonus:

clean:

fclean:

re:

.PHONY: all, clean, fclean, re, bonus
