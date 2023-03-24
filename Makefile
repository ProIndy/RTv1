# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 14:56:52 by ijaaskel          #+#    #+#              #
#    Updated: 2023/02/23 14:56:54 by ijaaskel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RTv1

SRC_DIR		=	src/

SRCS		=	calc_vector_direction.c		\
				check_for_hit.c				\
				exit.c						\
				light.c						\
				main.c						\
				normals.c					\
				raytrace.c					\
				read_file.c					\
				render.c					\
				scene.c						\
				solve_quadratic_equation.c	\
				vector_calculations.c		\
				vector_calculations_2.c

SRC			=	$(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR		=	objs/

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

LIBFT		=	-Llibft/ -lft

UNAME		:=	$(shell uname -s)
ifeq ($(UNAME), Darwin)
SDL			=	-I./frameworks/SDL2.framework/Headers/			\
				-I./frameworks/SDL2_ttf.framework/Headers/		\
				-I./frameworks/SDL2_image.framework/Headers/	\
				-F./frameworks

FRAMEWORKS	=	-rpath ./frameworks 	\
				-framework SDL2			\
				-framework SDL2_image	\
				-framework SDL2_mixer
endif

ifeq ($(UNAME), Linux)
FRAMEWORKS	=	-lSDL2
endif

INCLUDES	=	-I./includes/ -I./libft/ $(SDL)

MATH		=	-lm

HDR			=	rtv1.h

all:			$(NAME)

$(NAME):		$(OBJ)
	@make -C libft/
	@$(CC) $(FLAGS) $(OBJ) $(INCLUDES) $(MATH) $(LIBFT) $(FRAMEWORKS) -o $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C libft/

clean:
	@make -C libft/ clean
	@rm -Rf $(OBJ_DIR)

fclean:			clean
	@make -C libft/ fclean
	@rm -vf $(NAME)

re:				fclean all

rec:			re
	@make clean

.PHONY: all clean flcean re rec
