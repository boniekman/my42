/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:34:22 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:34:23 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FD 10

typedef struct		s_input
{
	char			str[BUFF_SIZE + 1];
	int				fd;
}					t_input;

int					get_next_line(int const fd, char **line);

#endif
