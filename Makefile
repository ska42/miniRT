# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 02:42:41 by lmartin           #+#    #+#              #
#    Updated: 2019/10/29 08:44:27 by lmartin          ###   ########.fr        #
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
				lstobjects.c \
				miniRT.c \
				sphere.c \
				vector_calculation.c \
				vector.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				$(CC) $(FLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAG) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

bonus:

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
