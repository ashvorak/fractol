# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by oshvorak          #+#    #+#              #
#    Updated: 2018/07/27 17:56:21 by oshvorak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror

SRC =	./src/main.c \
		./src/display.c \
		./src/mandelbrot.c \
		./src/julia.c \
		./src/hook.c

MLIB = make -C lib

LIB = lib/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	$(MLIB) 
	gcc $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(SRC) $(LIB) -o $(NAME)

clean:
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all