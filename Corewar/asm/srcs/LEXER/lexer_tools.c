/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:01:28 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:01:29 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				open_file(char *filename)
{
	char *extension;

	if (!(extension = ft_strrchr(filename, '.')))
		return (-1);
	if (!ft_strequ(extension, ".s"))
		return (-1);
	return (open(filename, O_RDONLY));
}

unsigned int	reverse_byte(unsigned int number)
{
	unsigned int	num;
	char			tmp;

	num = 0;
	tmp = ((number << 24) >> 24);
	num |= (tmp << 24);
	tmp = (((number >> 8) << 24) >> 24);
	num |= (tmp << 16);
	tmp = (((number >> 16) << 24) >> 24);
	num |= (tmp << 8);
	tmp = (((number >> 24) << 24) >> 24);
	num |= tmp;
	return (num);
}
