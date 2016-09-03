NAME= push_swap
FLAGS= -Wall -Wextra -Werror -Ofast
SRC= main.c \
	 list.c \
	 moves.c \
	 parsing.c \
	 algo.c \
	 algo_tools.c

OBJ=$(SRC:.c=.o)
all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc -c $(SRC)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L libft/ -lft

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
.PHONY: all clean fclean re
