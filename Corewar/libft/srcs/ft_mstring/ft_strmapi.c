/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:56:41 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:42 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	ptr = ft_strnew(size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
