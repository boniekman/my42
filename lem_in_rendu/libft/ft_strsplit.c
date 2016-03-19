/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:41:21 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/03 18:11:35 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(char *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char		**fill_tab(char **tab, char *str, char c)
{
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	l = 0;
	while (i <= (int)ft_strlen(str))
	{
		if (str[i] != c && str[i] != '\0')
			l++;
		if ((str[i] == c || str[i] == '\0') && str[i - 1] != c)
		{
			tab[j] = (char*)malloc(sizeof(char) * (l + 1));
			if (tab[j] == NULL)
				return (NULL);
			tab[j] = ft_strncpy(tab[j], &str[i - l], l);
			j++;
			l = 0;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	char		*str;

	str = ft_strstrim(s, c);
	ret = (char**)malloc(sizeof(char*) * (words(str, c) + 1));
	if (ret == NULL)
		return (NULL);
	if (str[0] == '\0')
	{
		ret[0] = NULL;
		return (ret);
	}
	ret = fill_tab(ret, str, c);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
