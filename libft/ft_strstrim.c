/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:23:49 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:29:10 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	counts(char *st, int *i, int *l, char c)
{
	*l = (int)ft_strlen(st) - 1;
	while (st[*i] == c)
	{
		if (*i == *l)
			break ;
		(*i)++;
	}
	while (st[*l] == c)
	{
		if (*l == 0)
			break ;
		(*l)--;
	}
}

char		*ft_strstrim(char const *s, char c)
{
	char	*st;
	char	*ret;
	int		l;
	int		i;
	int		j;

	j = 0;
	i = 0;
	l = 0;
	st = (char*)s;
	counts(st, &i, &l, c);
	if (l == 0)
		return (ft_strnew(0));
	ret = (char*)malloc((l - i + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (j < l - i + 1)
	{
		ret[j] = st[i + j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
