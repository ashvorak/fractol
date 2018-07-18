# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by oshvorak          #+#    #+#              #
#    Updated: 2018/06/09 18:28:31 by oshvorak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC =	./src/main.c

MLIB = make -C lib

LIB = lib/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

clean:
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all