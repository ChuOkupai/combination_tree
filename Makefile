# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/08 19:17:12 by asoursou          #+#    #+#              #
#    Updated: 2020/03/08 19:24:39 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= comb
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast
SRC		= comb.c \
		  list.c \
		  node.c

$(NAME): $(SRC) comb.h
	$(CC) $(CFLAGS) $(SRC) -o $@

all: $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
