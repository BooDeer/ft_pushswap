# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 15:58:41 by hboudhir          #+#    #+#              #
#    Updated: 2021/07/06 19:55:16 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
FLAGS	= -Wall -Werror -Wextra
AR		= ar -rc
SRC		= 
PROGRAM = push_swap
BONUS	= checker
NAME	= push_swap.a
MAKE 	= make -C
all:	$(PROGRAM)

$(PROGRAM):
	@make -C pushswap/

clean:
	@make clean -C pushswap
	@make clean -C libft 
	@make clean -C checker_src
fclean: clean
	-@rm	$(PROGRAM)
	-@rm	$(BONUS)

bonus: $(BONUS)
	
$(BONUS):
	make -C checker_src
	
re:	fclean all