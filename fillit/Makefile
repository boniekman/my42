# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 18:23:18 by ngrasset          #+#    #+#              #
#    Updated: 2015/12/02 14:27:53 by ngrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c\
	  controller.c\
	  file_parsing.c\
	  pieces_functions.c\
	  pieces_functions_bis.c\
	  matrix.c\
	  placement.c\
	  strtab_functions.c

INCLUDES = -I libft/includes/ -I./includes
LIBS = -L libft/ -lft
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	make -C libft/
	gcc -o $(NAME) $^ $(LIBS)

%.o: srcs/%.c
	gcc $(CFLAGS) $(INCLUDES) -c $^
clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
