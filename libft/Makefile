# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:44:19 by mbonowic          #+#    #+#              #
#    Updated: 2016/05/18 11:31:14 by mbonowic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strstrim.c \
		get_next_line.c \
		ft_split.c \
		ft_latoi.c \
		\
		ft_printf.c \
	  	ft_putwchar.c \
	  	bools.c \
	  	put_colors.c \
	  	hour.c \
	  	instruction.c \
	  	conversion.c \
	  	preci_field.c \
	  	flag.c \
	  	modifier.c \
	  	di.c \
	  	o.c \
	  	xp.c \
	  	cs.c \
	  	u.c \
	  	b.c \
	  	a.c \
	  	n.c \
	  	ft_strlen_wchar.c \
	  	ft_itoa_base.c \
	  	ft_uitoa_base.c \
	  	padding_ws.c \
	  	padding_c.c \
	  	ft_round.c \
	  	ft_isspace.c \

HEADERS = libft.h

FLAGS = -Wall -Wextra -Werror

OBS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(SRC) -I $(HEADERS)
	ar -rcs $(NAME) $(OBS)
	ranlib $(NAME)

clean:
	rm -f $(OBS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY : all clean fclean re
