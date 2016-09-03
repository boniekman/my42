/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:55:36 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:26 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
