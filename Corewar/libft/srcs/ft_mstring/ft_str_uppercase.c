/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_uppercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:57:34 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:38 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>

char	*ft_str_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
