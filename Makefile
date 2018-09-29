# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:14:50 by hshakula          #+#    #+#              #
#    Updated: 2018/09/22 21:11:14 by hshakula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FULL_PATH=$(shell pwd)
BUILD_PATH=$(FULL_PATH)/build

all: build_folder	
	@$(shell cd $(BUILD_PATH) && \
		cmake -DFULL_PATH="$(FULL_PATH)" -DCMAKE_VERBOSE="OFF" ..  > /dev/null && \
		cmake --build . --config Release -- -j4 > /dev/null)

build_folder:
	@mkdir -p $(BUILD_PATH)

clean:
	@rm -rf $(BUILD_PATH)

fclean: clean
	@rm -f corewar
	@rm -f asm

re: fclean all

.PHONY: re fclean all clean
