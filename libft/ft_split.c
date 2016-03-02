/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:02:11 by exam              #+#    #+#             */
/*   Updated: 2016/03/02 09:22:15 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char *str)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') &&
			(str[i - 1] != ' ' && str[i - 1] != '\n' && str[i - 1] != '\t'))
		{
			w++;
		}
		i++;
	}
	if (str[i] == '\0' && (str[i - 1] != ' ' &&
		str[i - 1] != '\n' && str[i - 1] != '\t'))
		w++;
	return (w);
}

static char	**next_word(char **ret, char *str, int i)
{
	int		j;

	if (str[0] == '\0')
	{
		ret[i] = NULL;
		return (ret);
	}
	j = 0;
	while (str[j] != ' ' && str[j] != '\n' && str[j] != '\t' && str[j] != '\0')
	{
		j++;
	}
	ret[i] = (char*)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[j] != ' ' && str[j] != '\n' && str[j] != '\t' && str[j] != '\0')
	{
		ret[i][j] = str[j];
		j++;
	}
	ret[i][j] = '\0';
	if (str[j] == '\0')
		return (next_word(ret, &str[j], i + 1));
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		j++;
	return (next_word(ret, &str[j], i + 1));
}

char		**ft_split(char *str)
{
	char	**ret;
	int		i;
	int		w;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	str = &str[i];
	i = 0;
	w = words(str);
	ret = (char**)malloc(sizeof(char*) * (w + 1));
	if (ret == NULL)
		return (NULL);
	return (next_word(ret, str, 0));
}
