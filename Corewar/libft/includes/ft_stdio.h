/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:34:00 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:34:00 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>
# include <wchar.h>
# include <ft_string.h>

int					ft_putchar(char c);
int					ft_putwchar(wchar_t letter);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr(const char *s);
int					ft_putstr_fd(const char *s, int fd);
int					ft_putendl(const char *s);
int					ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_endl(int n);
void				ft_putnbr_fd(int n, int fd);

#endif
