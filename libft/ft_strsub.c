/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 22:20:12 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:24:08 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	ptr = ft_strnew(len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	s += start;
	while (len)
	{
		ptr[i] = s[i];
		len--;
		i++;
	}
	return (ptr);
}
