/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:52:31 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:27 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strdup(const char *s1)
{
	char *s2;

	s2 = ft_strnew(ft_strlen(s1));
	if (s2 != NULL)
		ft_strcpy(s2, s1);
	return (s2);
}
