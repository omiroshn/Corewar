# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:14:50 by hshakula          #+#    #+#              #
#    Updated: 2018/06/18 00:07:08 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./src/ ./../../include/

HEADERS = 	./include/ft_printf.h \
			./src/buffer_manager.h \
			./src/color.h \
			./src/flags.h \
			./src/ftoa.h \
			./src/padding.h \
			./src/print.h \
			./src/specifier.h

SRC_NAME =	print.c \
			color.c \
			print_character.c \
			print_radix.c \
			print_pointer.c \
			print_string.c \
			print_decimal.c \
			print_float.c \
			itoa_base.c \
			ftoa.c \
			casts/cast3.c \
			casts/cast2.c \
			casts/cast1.c \
			ft_printf.c \
			padding.c \
			flags.c \
			specifier.c \
			sub_specifiers.c \
			buffer_manager.c

SUBFOLDERS = casts
			
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_SUBFOLDER = $(addprefix $(OBJ_PATH), $(SUBFOLDERS))

FLAGS = -Wall -Wextra -Werror -O3
CC = clang
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_SUBFOLDER)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -fv $(OBJ)
	@rm -rfv $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	@norminette src include

.PHONY: re fclean all clean norme
