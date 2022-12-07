# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ali <ali@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:36:53 by msariasl          #+#    #+#              #
#    Updated: 2022/12/07 10:09:24 by ali              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PF_FILES = $(shell find ../*.c)
GNL_FILES = $(shell find *.c)
PREPARE = cd .. && make re

test:
	@clear
	@echo "\n\n- - -> Please check following files! <- - -\n\n"
	@$(PREPARE)
	@nm ../libftprintf.a
	@echo "\n\n- - -> Please check following lines! (2/n) <- - -\n\n"
	@gcc $(PF_FILES) $(GNL_FILES)
	@./a.out
	
	
clean:
	@rm -rf a.out
	@cd .. &&  make clean && make fclean
	@clear


#gcc -Wall -Wextra -Werror libftprintf.a main.c 
#./a.out  									cd printfTesterBy_msariasl