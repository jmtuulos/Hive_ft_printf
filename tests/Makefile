# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 09:59:08 by smarvin           #+#    #+#              #
#    Updated: 2022/02/09 15:02:39 by jheiskan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SRC = main.c
FLAGS =
CFLAGS = -g
INCL = Iincludes/
OBJ = $(SRC:.c=.o)

all: test $(NAME)

test:
	cd ../ && make re
	@mv ../libftprintf.a ./
	@echo "libftprintf.a moved to test folder"

$(NAME): $(OBJ)
#make -C libft/ "These lines are if there is no libft created yet"
#@echo "Library created"
	gcc -ggdb $(FLAGS) $(SRC) -L. -lftprintf -o $(NAME)
	@echo "Compiled"
clean:
#make -C libft/ clean
	/bin/rm -f $(OBJ)
	make -C ../ clean

fclean: clean
#make -C libft/ fclean
	make -C ../ fclean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	/bin/rm -f libftprintf.a

re: fclean all
