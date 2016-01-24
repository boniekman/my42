/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:25 by mbonowic          #+#    #+#             */
/*   Updated: 2016/01/24 12:13:08 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%d %s\n", i, line);
	}
	printf("%d\n", i);
	if (fd != 0)
		close(fd);
	return (0);
}
