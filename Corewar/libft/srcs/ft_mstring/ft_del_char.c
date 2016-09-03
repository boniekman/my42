/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:57:19 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:19:11 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

int		ft_del_char(char *str, char c)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == c)
		{
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
			i++;
		}
		else
			str++;
	}
	return (i);
}
