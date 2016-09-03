/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:29:52 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/22 12:48:09 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MSTRING_H
# define FT_MSTRING_H
# include <stdlib.h>
# include <ft_string.h>
# define LEFT 1
# define RIGHT 2
# define BOTH 3

/*
** allocation / deletion
*/
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** basic tools
*/
char				*ft_strrev(char *str);
char				*ft_strtrim(char const *s);
char				*ft_strtrim_free(char *s);
char				*ft_str_uppercase(char *str);
char				*ft_str_lowercase(char *str);
void				ft_add_char(char *str, char c);
int					ft_del_char(char *str, char c);
int					ft_str_get_index(char *str, char c);
int					ft_str_count_char(const char *str, int c);
void				ft_replace_char(char *s, char old_letter, char new_letter);

/*
** comparison
*/
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** iteration
*/
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** join / split
*/
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_mul(char const *s, const char *c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_sep(char *s1, char *s2, char *sep);
char				*ft_strjoin_free(char *s1, char *s2, char mode);

/*
** w_char
*/
int					strlen_wchar(wchar_t *str);

#endif
