# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 15:58:41 by hboudhir          #+#    #+#              #
#    Updated: 2021/04/21 16:00:00 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
FLAGS	= -Wall -Werror -Wextra
AR		= ar -rc
SRC		= main.c
PROGRAM = minishell
NAME	= push_swap.a
MAKE 	= make -C
all:	$(NAME)

%.o:	%.c
	$(CC) -c $(FLAGS) $<

$(NAME): $(SRC:.c=.o)
	@echo "Creating the program."
	$(MAKE) libft
	@$(AR) $(NAME) $(SRC:.c=.o)
	ranlib $(NAME)
	$(CC) $(FLAGS) -o $(PROGRAM) $(NAME)

clean:
	@rm -rf $(SRC:.c=.o) $(NAME)
fclean: clean
	@rm -rf $(PROGRAM)

re:	fclean all