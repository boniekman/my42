# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/24 14:32:18 by mbonowic          #+#    #+#              #
#    Updated: 2016/02/24 18:09:58 by mbonowic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol
FLAGS= -Wall -Wextra -Werror -Ofast
SRC= main.c \
	 fractols.c \
	 draw.c \
	 math.c \
	 hook.c \
	 color.c

OBJ=$(SRC:.c=.o)
all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/ all
	make -C minilibx/ clean
	make -C minilibx/
	gcc -c $(FLAGS) $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L libft/ -lft -L minilibx/ -lmlx -framework OpenGl -framework AppKit

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all
.PHONY: all clean fclean re
