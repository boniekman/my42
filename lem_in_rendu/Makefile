NAME= lem_in
FLAGS= -Wall -Wextra -Werror -Ofast
SRC= main.c \
	 list.c \
	 parsing.c \
	 parse_tools.c \
	 restrictions.c \
	 passage_parsing.c \
	 debug.c \
	 algo.c \
	 routes.c \
	 route_list.c \



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
