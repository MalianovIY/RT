# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 23:48:56 by ahorker           #+#    #+#              #
#    Updated: 2019/01/13 22:10:02 by ahorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
OPT = -I $(HEADER) -c
NAME = libgm.a
HEADER = ./include
FUNCS = $(shell cat ./include/libgm.h | grep -Eo "gm_\w+")
SRC = $(FUNCS:=.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $(OPT) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all