# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/19 17:33:06 by sdelardi          #+#    #+#              #
#    Updated: 2016/07/19 17:33:08 by sdelardi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

all: $(NAME)

$(NAME): $(O_FILES)
	make -C libft
	make -C VM
	make -C asm

clean:
	make clean -C libft
	make clean -C VM
	make clean -C asm

fclean: clean
	make fclean -C libft
	make fclean -C VM
	make fclean -C asm

re: fclean all
