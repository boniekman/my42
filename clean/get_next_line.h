/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:54:52 by mbonowic          #+#    #+#             */
/*   Updated: 2015/12/12 18:11:40 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_ctrl
{
	char		*sav;
	int			fd;
	int			flag;
}				t_ctrl;

int				get_next_line(int const fd, char **line);

#endif
