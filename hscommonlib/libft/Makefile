# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:47:08 by hshakula          #+#    #+#              #
#    Updated: 2018/09/04 12:20:35 by hshakula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH = ./obj/
SRC_PATH = ./src/
PRINTF_PATH = ./src/ft_printf/

HEADERS = ./src/get_next_line_private.h ./include/get_next_line.h ./include/libft.h

NAME = libft.a

SRC_FILES =	ft_merge.c \
			ft_split_str_to_int.c \
			ft_sizeofnumber.c \
			ft_atoi_base.c \
			ft_countwords.c \
			ft_getword.c \
			ft_isnum.c \
			ft_realloc.c \
			ft_islower.c \
			ft_strsplit.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putchar_fd.c \
			ft_strtrim.c \
			ft_strjoin.c \
			ft_strsub.c \
			ft_strmapi.c \
			ft_strmap.c \
			ft_striteri.c \
			ft_strlcat.c \
			ft_strrev.c \
			ft_power.c \
			ft_bzero.c \
			ft_memset.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_isspace.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_isupper.c \
			ft_tolower.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strncpy.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_itoa.c \
			ft_strisdigit.c \
			ft_strisalpha.c \
            ft_strislower.c \
            ft_strisupper.c \
            ft_strisspaces.c \
			ft_charinsequal.c \
			get_next_line.c \
			is_directory.c \
			ft_swap.c \
			pair.c \
			ft_atod.c \
			fs_path_manip.c

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_PRINTF_FILES =	print.o \
					color.o \
					print_character.o \
					print_radix.o \
					print_pointer.o \
					print_string.o \
					print_decimal.o \
					print_float.o \
					itoa_base.o \
					ftoa.o \
					casts/cast3.o \
					casts/cast2.o \
					casts/cast1.o \
					ft_printf.o \
					padding.o \
					flags.o \
					specifier.o \
					sub_specifiers.o \
					buffer_manager.o

PRINTF_OBJ = $(addprefix $(PRINTF_PATH)obj/, $(OBJ_PRINTF_FILES))

INC = -I./include -I./src/ft_printf/include

FLAGS = -Wall -Werror -Wextra -O3
CC = clang

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

all: $(NAME)

$(NAME): printf $(OBJ)
	@ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

printf:
	@make -C src/ft_printf

clean:
	@make -C src/ft_printf clean
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C src/ft_printf fclean
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC) include
	@make -C ft_printf norme

.PHONY: re fclean all clean zip