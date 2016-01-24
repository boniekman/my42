all:
	make -C libft/ re
	gcc -c main.c get_next_line.c
	gcc -o gnl main.o get_next_line.o -L libft -lft

clean:
	rm -f *o

fclean: clean
	rm -f gnl

re: fclean all
