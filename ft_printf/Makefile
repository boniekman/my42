NAME= libftprintf.a
FLAGS= -Wall -Wextra -Werror -Ofast
SRC= ft_printf.c \
	 listc.c \


OBJ=$(SRC:.c=.o)
all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/ all
	gcc -c $(FLAGS) $(SRC)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
.PHONY: all clean fclean re
