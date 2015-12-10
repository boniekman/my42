NAME = test_gnl

SRCS = get_next_line.c main.c

OBJ = $(SRCS:.c=.o)

FLAGS= 

all: $(NAME)

$(NAME) :
	make -C libft/ fclean
	make -C libft
	gcc $(FLAGS) -I libft -c get_next_line.c
	gcc $(FLAGS) -I libft -c main.c
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
