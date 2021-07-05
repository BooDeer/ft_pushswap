# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 09:34:05 by hboudhir          #+#    #+#              #
#    Updated: 2021/07/05 09:54:37 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc 		= gcc
FLAGS	= -Wall -Wextra -Werror
AR		= ar -rc
SRC		= big_list.c error_manage.c instructions.c push_swap.c simple_action.c simple_action2.c \
		  stack_handler.c utils_01.c utils.c
PROGRAM = push_swap
NAME	= push_swap.a
LIB		= ../libft/libft.a
all: $(PROGRAM)

%.o: %.c
	@$(CC) -c $(FLAGS) $<

$(PROGRAM): $(SRC:.c=.o)
	@echo "[Push_swap] ===> Building the program."
	@make -C ../libft
	@$(AR) $(NAME) $(SRC:.c=.o)
	ranlib $(NAME)
	$(CC) $(FLAGS) -o $(PROGRAM) $(NAME) $(LIB)

clean:
	@echo "[Push_swap ===> cleaning object files.]"
	@rm $(SRC:.c=.o) $(NAME)
	@make clean -C ../libft

fclean: clean
	@echo "[Push_swap ===> cleaning everything.]"
	@rm $(PROGRAM)

re: fclean all