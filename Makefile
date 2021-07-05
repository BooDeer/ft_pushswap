# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 15:58:41 by hboudhir          #+#    #+#              #
#    Updated: 2021/07/05 09:38:35 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
FLAGS	= -Wall -Werror -Wextra
AR		= ar -rc
SRC		= 
PROGRAM = push_swap
NAME	= push_swap.a
MAKE 	= make -C
all:	$(NAME)

%.o:	%.c
	cd push_swap/ ; echo "I'm in!"; \
	$(CC) -c $(FLAGS) $<

$(NAME): $(SRC:.c=.o)
	@echo "Creating the program."
	$(MAKE) libft
	@$(AR) $(NAME) $(SRC:.c=.o)
	ranlib $(NAME)
	$(CC) $(FLAGS) -o $(PROGRAM) $(NAME)

clean:
	@rm  $(SRC:.c=.o) $(NAME)
	@make clean -C libft 
fclean: clean
	@rm  $(PROGRAM)

re:	fclean all