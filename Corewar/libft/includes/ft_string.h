/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:34:19 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:34:57 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <stdlib.h>
# include <ft_mstring.h>
# include <ft_memory.h>

void				ft_strclr(char *s);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** provisoire
*/
int					count_significant_bit(int value);

#endif
