/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:38:04 by mbonowic          #+#    #+#             */
/*   Updated: 2015/12/18 12:14:59 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		f;

	line = NULL;
	argc = 0;
	fd = open(argv[1], O_RDONLY);
	f = 1;
	while (f == 1)
	{
		f = get_next_line(fd, &line);
		printf("%s\n", line);
/*printf("BUFF_SIZE = %d\n", BUFF_SIZE);
	f = get_next_line(fd, &line);
			printf("1: %s <- chars: %d\n", line, (int)ft_strlen(line));
f = get_next_line(fd, &line);
			printf("2: %s <- chars: %d\n", line, (int)ft_strlen(line));
f = get_next_line(fd, &line);
			printf("3: %s <- chars: %d\n", line, (int)ft_strlen(line));
f = get_next_line(fd, &line);
			printf("4: %s <- chars: %d\n", line, (int)ft_strlen(line));
f = get_next_line(fd, &line);
			printf("5: %s <- chars: %d\n", line, (int)ft_strlen(line));
f = get_next_line(fd, &line);
			printf("6: %s <- chars: %d\n", line, (int)ft_strlen(line));
f = get_next_line(fd, &line);
			printf("7: %s <- chars: %d\n", line, (int)ft_strlen(line));
			printf("%d\n", f);*/
	}
	//printf("%s\n", line);
	close(fd);
	return (0);
}
