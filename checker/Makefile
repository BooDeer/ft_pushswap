# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 16:04:03 by hboudhir          #+#    #+#              #
#    Updated: 2021/07/05 11:11:11 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
FLAGS	= -Wall -Werror -Wextra
AR		= ar -rc
SRC		= checker.c
PROGRAM = checker
NAME	= checker.a
LIB 	= ../libft/libft.a
all:	$(PROGRAM)

%.o:	%.c
	$(CC) -c $(FLAGS) $<

$(NAME): $(SRC:.c=.o)
	@echo "[Checker] ===> creating the program."
	@make -C ../libft
	@$(AR) $(NAME) $(SRC:.c=.o)
	@ranlib $(NAME)
	$(CC) $(FLAGS) -o $(PROGRAM) $(NAME) $(LIB)

clean:
	@make clean -C ../libft
	@rm -rf $(SRC:.c=.o) $(NAME)
fclean: clean
	@make fclean -C ../libft
	@rm -rf $(PROGRAM)

re:	fclean all