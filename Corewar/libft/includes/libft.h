/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:13:54 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:34:43 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include <ft_array.h>
# include <ft_ctype.h>
# include <ft_lst.h>
# include <ft_memory.h>
# include <ft_mstring.h>
# include <ft_stdio.h>
# include <ft_stdlib.h>
# include <ft_string.h>
# include <get_next_line.h>

# define C_RED "\x1b[31m"
# define C_GREEN "\x1b[32m"
# define C_YELLOW "\x1b[33m"
# define C_BLUE "\x1b[34m"
# define C_MAGENTA "\x1b[35m"
# define C_CYAN "\x1b[36m"
# define C_LRED "\x1b[1;31m"
# define C_LGREEN "\x1b[1;32m"
# define C_LYELLOW "\x1b[1;33m"
# define C_LBLUE "\x1b[1;34m"
# define C_LMAGENTA "\x1b[1;35m"
# define C_LCYAN "\x1b[1;36m"
# define C_RESET "\x1b[0m"

/*
** INT AND CO
*/

int					count_nb_octet(wchar_t letter);
int					count_significant_bit(int value);

#endif
