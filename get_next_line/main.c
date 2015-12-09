/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:38:04 by mbonowic          #+#    #+#             */
/*   Updated: 2015/12/08 15:26:11 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	argc++;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) >= 0)
	{
		printf("%s\n", line);
	}
	return (0);
}
