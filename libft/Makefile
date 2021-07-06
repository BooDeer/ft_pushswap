# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 19:10:52 by hboudhir          #+#    #+#              #
#    Updated: 2021/07/05 11:34:27 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

AR		= ar

NAME	= libft.a

LIB		= libft.h

FLAGS	= -Wall -Werror -Wextra

SRC 	= get_next_line.c get_next_line_utils.c \
 		ft_strlen.c ft_bzero.c ft_memset.c \
		ft_strchr.c ft_atoi.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c  \
		ft_calloc.c ft_strdup.c  ft_strjoin.c ft_split.c ft_itoa.c \
		ft_strcmp.c

FILESB = ft_lstnew.c ft_lstadd_font.c ft_lstsize.c ft_lstsize.c	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OBJB = ft_lstnew.o ft_lstadd_font.o	ft_lstsize.o ft_lstsize.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o	ft_lstiter.o
all: $(NAME)

%.o:	%.c
	@$(CC) -c $(FLAGS) $<

$(NAME): $(SRC:.c=.o)
	@$(AR) rc $(NAME) $(SRC:.c=.o)
	@ranlib $(NAME)

clean:
	@echo "[Libft] ===> cleaning object files."
	@rm -rf $(SRC:.c=.o) $(OBJB)

fclean: clean
	@echo "[Libft] ==> Cleaning all the object files . . . . ."
	@rm -rf $(NAME)

bonus:
	@$(CC) $(FLAGS) -c $(FILESB) -I $(LIB)
	@$(AR) rc $(NAME) $(OBJB)

re: fclean all
