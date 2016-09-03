/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:54:54 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;

	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr != NULL)
	{
		ptr = ft_strcat(ptr, s1);
		ptr = ft_strcat(ptr, s2);
	}
	return (ptr);
}
