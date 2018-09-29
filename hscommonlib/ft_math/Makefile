# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Admin <Admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:47:08 by hshakula          #+#    #+#              #
#    Updated: 2018/08/31 20:46:13 by Admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

NAME = ft_math.a
SRC_NAME =	scalar_geometry.c \
			scalar_algebra.c \
			scalar_conditional.c \
			vec3_constructors.c \
			vec3_base_operations.c \
			vec3_scalar_operations.c \
			vec3_geometry.c \
			vec3_geometry_2.c \
			vec3_geometry_3.c \
			vec4_constructors.c \
			vec4_base_operations.c \
			vec4_scalar_operations.c \
			vec4_geometry.c \
			quaternion_constructors.c \
			quaternion_base_operations.c \
			mat4_constructors.c \
			mat4_base_operations.c \
			mat4_transform.c \
			mat4_mvp.c

OBJ_NAME = $(SRC_NAME:.c=.o)
FLAGS = -O3 -msse3 -Wall -Werror -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-static-in-inline -pedantic
CC = clang

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH)) $(addprefix -I, $(LIB_INC))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIB)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: re fclean all clean