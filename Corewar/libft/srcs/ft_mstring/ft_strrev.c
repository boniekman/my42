/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:57:48 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:43 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

char	*ft_strrev(char *str)
{
	int		j;
	int		i;
	char	a;

	j = 0;
	i = ft_strlen(str) - 1;
	while (i < j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i++;
		j--;
	}
	return (str);
}
