# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 02:42:41 by lmartin           #+#    #+#              #
#    Updated: 2019/12/04 16:53:34 by lmartin          ###   ########.fr        #
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

SRC =			maths/rotation.c \
				maths/vector_calculation.c \
				maths/vector_color.c \
				maths/vector_translation.c \
				maths/vector.c \
				\
				parsing/parsing_object.c \
				parsing/parsing_scene_elem.c \
				parsing/parsing.c \
				\
				raytracing/intersect/intersect.c \
				raytracing/intersect/intersect_cylinder.c \
				raytracing/intersect/intersect_plan.c \
				raytracing/intersect/intersect_sphere.c \
				raytracing/intersect/intersect_square.c \
				raytracing/intersect/intersect_triangle.c \
				raytracing/lightning/lightning.c \
				raytracing/lightning/check_light_cylinder.c \
				raytracing/lightning/check_light.c \
				raytracing/lightning/set_color.c \
				raytracing/lightning/shiny.c \
				raytracing/raytracing.c \
				raytracing/reflect.c \
				\
				scene/camera.c \
				scene/canvas.c \
				scene/handle_key.c \
				scene/image.c \
				scene/light.c \
				scene/scene_cpy.c \
				scene/scene.c \
				scene/objects/cylinder.c \
				scene/objects/lstobjects.c \
				scene/objects/plan.c \
				scene/objects/sphere.c \
				scene/objects/square.c \
				scene/objects/triangle.c \
				\
				utils/error.c \
				utils/export_bmp.c \
				utils/ft_strcmp.c \
				utils/get_next_line.c \
				utils/no_leaks.c \
				utils/utils.c \
				\
				minirt.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./minilibx_opengl
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
