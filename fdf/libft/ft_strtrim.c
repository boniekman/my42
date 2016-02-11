/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:23:49 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 16:02:43 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count(char *st, int *i, int *l)
{
	*l = (int)ft_strlen(st) - 1;
	while (st[*i] == ' ' || st[*i] == '\n' || st[*i] == '\t')
	{
		if (*i == *l)
			break ;
		(*i)++;
	}
	while (st[*l] == ' ' || st[*l] == '\n' || st[*l] == '\t')
	{
		if (*l == 0)
			break ;
		(*l)--;
	}
}

char		*ft_strtrim(char const *s)
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
	count(st, &i, &l);
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
