# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 15:58:41 by hboudhir          #+#    #+#              #
#    Updated: 2021/07/05 10:21:49 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
FLAGS	= -Wall -Werror -Wextra
AR		= ar -rc
SRC		= 
PROGRAM = push_swap
NAME	= push_swap.a
MAKE 	= make -C
all:	$(PROGRAM)

$(PROGRAM):
	@make -C pushswap/

clean:
	@make clean -C pushswap
	@make clean -C libft 
fclean: clean
	@rm  $(PROGRAM)

re:	fclean all