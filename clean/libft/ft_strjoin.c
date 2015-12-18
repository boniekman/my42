/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:52:07 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 13:46:53 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) +
				ft_strlen((char*)s2)));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while ((char)s1[i] != '\0')
	{
		ret[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[j] != '\0')
	{
		ret[i + j] = (char)s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
