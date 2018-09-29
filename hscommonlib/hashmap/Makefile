# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:47:08 by hshakula          #+#    #+#              #
#    Updated: 2018/06/22 13:43:10 by hshakula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./../libft/include/ ./../libft/src/ft_printf/include/

HEADERS = ./include/hashmap.h ./src/hashmap_private.h

NAME = hashmap.a
SRC_NAME = init.c io_hashmap.c manage_hashmap.c size.c string_key_funcs.c \
			key_type_descriptors.c
			
OBJ_NAME = $(SRC_NAME:.c=.o)
FLAGS = -O3 -Wall -Werror -Wextra
CC = clang

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: re fclean all clean zip