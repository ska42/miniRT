# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 02:42:41 by lmartin           #+#    #+#              #
#    Updated: 2019/11/04 02:44:07 by lmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

DIR_OBJS =		./

LIBMLX =		libmlx.dylib \
				libmlx.a

SRC =			canvas.c \
				light.c \
				lightning.c \
				lstobjects.c \
				miniRT.c \
				raytracing.c \
				reflect.c \
				scene.c \
				sphere.c \
				vector_calculation.c \
				vector_color.c \
				vector.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./minilibx_mms
				@make -C ./minilibx_opengl
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				@cp ./minilibx_opengl/libmlx.a libmlx.a
				$(CC) $(FLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

bonus:

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
