/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:52:55 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:19:32 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

void		ft_replace_char(char *s, char old_letter, char new_letter)
{
	while (*s)
	{
		if (*s == old_letter)
			*s = new_letter;
		s++;
	}
}
