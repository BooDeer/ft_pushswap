# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 16:04:03 by hboudhir          #+#    #+#              #
#    Updated: 2021/07/12 17:44:11 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
FLAGS	= -Wall -Werror -Wextra
SRC		= checker.c checker2.c
PROGRAM = checker
LIB 	= ../libft/libft.a ../pushswap/push_swap.a
all:	$(PROGRAM)

$(PROGRAM):  checker.c checker2.c
	@echo "[Checker] ===> creating the program."
	@make -C ../libft
	@make -C ../pushswap
	@rm ../push_swap
	@$(CC) $(FLAGS) -o $(PROGRAM) $(NAME) $(LIB) checker.c checker2.c
	@mv $(PROGRAM) ..

clean:
	@make clean -C ../libft
	@rm -rf $(SRC:.c=.o) $(NAME)
fclean: clean
	@make fclean -C ../libft
	@rm -rf $(PROGRAM)

re:	fclean all