/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:54:54 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

char	*ft_strjoin_free(char *s1, char *s2, char mode)
{
	char *ptr;

	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr != NULL)
	{
		ptr = ft_strcat(ptr, s1);
		ptr = ft_strcat(ptr, s2);
	}
	if (mode == LEFT || mode == BOTH)
		ft_strdel(&s1);
	if (mode == RIGHT || mode == BOTH)
		ft_strdel(&s2);
	return (ptr);
}
