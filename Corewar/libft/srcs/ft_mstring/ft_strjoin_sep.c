/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:57:39 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

char	*ft_strjoin_sep(char *s1, char *s2, char *sep)
{
	char	*tmp;

	tmp = ft_strjoin(s1, sep);
	tmp = ft_strjoin_free(tmp, s2, RIGHT);
	return (tmp);
}
