/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_mul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:07:04 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:43 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

static int	ft_remove_char(char *s, const char *c)
{
	int wcount;
	int word;

	word = 0;
	wcount = 0;
	while (*s)
	{
		if (!ft_strchr(c, *s) && word == 0)
		{
			wcount++;
			word = 1;
		}
		else if (ft_strchr(c, *s))
		{
			*s = '\0';
			word = 0;
		}
		s++;
	}
	return (wcount);
}

char		**ft_strsplit_mul(char const *s, const char *c)
{
	char	*str;
	int		count;
	int		j;
	char	**ptr;
	char	*temp;

	j = 0;
	if ((str = ft_strdup((char*)s)) == NULL)
		return (NULL);
	temp = str;
	count = ft_remove_char(str, c);
	ptr = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	while (count)
	{
		while (*str == '\0')
			str++;
		ptr[j] = ft_strsub(str, 0, ft_strlen(str));
		while (*str != '\0')
			str++;
		count--;
		j++;
	}
	ptr[j] = 0;
	ft_strdel(&temp);
	return (ptr);
}
