/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:23:38 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/19 11:23:07 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <float.h>

# define PRED "\x1b[31m"
# define PGREEN "\x1b[32m"
# define PYELLOW "\x1b[33m"
# define PBLUE "\x1b[34m"
# define PMAGENTA "\x1b[35m"
# define PCYAN "\x1b[36m"
# define PLRED "\x1b[1;31m"
# define PLGREEN "\x1b[1;32m"
# define PLYELLOW "\x1b[1;33m"
# define PLBLUE "\x1b[1;34m"
# define PLMAGENTA "\x1b[1;35m"
# define PLCYAN "\x1b[1;36m"
# define PRESET "\x1b[0m"

# define BUFF_SIZE 64

typedef struct		s_part
{
	unsigned long	mantisa : 52;
	unsigned long	exponent : 11;
	unsigned long	sign : 1;
}					t_part;

union				u_double
{
	double			d;
	t_part			parts;
	unsigned long	u;
};

typedef struct		s_printf
{
	char			is_zero;
	size_t			nbr_zero;
	char			is_minus;
	size_t			nbr_minus;
	char			is_plus;
	char			is_space;
	size_t			nbr_space;
	char			is_hash;
	char			is_preci;
	int				nbr_preci;
	char			is_field;
	int				nbr_field;
	char			*modifier;
	char			*instr;
	int				*count;
	char			conversion;
	int				print;
}					t_printf;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *dst, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
long				ft_latoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int star, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_strstrim(char const *s, char c);
int					get_next_line(int fd, char **line);
char				**ft_split(char *str);

int					ft_printf(const char *format, ...);
int					conversion(char *str, va_list ap, int *count);
void				instruction(t_printf *ptr, va_list ap);
int					flag_control(t_printf *ptr, int index);
int					preci_field(t_printf *ptr, int index,
		va_list ap);
void				modifier(t_printf *ptr, char *modif);
void				pad_after(t_printf *ptr, int length);

void				handler_di(t_printf *ptr, va_list ap);
void				handler_u(t_printf *ptr, va_list ap);
void				handler_b(t_printf *ptr, va_list ap);
void				handler_o(t_printf *ptr, va_list ap);
void				handler_xp(t_printf *ptr, va_list ap);
void				handler_cs(t_printf *ptr, va_list ap);
void				handler_a(t_printf *ptr, va_list ap);
void				handler_n(t_printf *ptr, va_list ap,
		int count);

int					is_flag(char *instr);
int					is_preci(char *instr);
int					is_modifier(char *instr);
void				print_field_c(t_printf *ptr);
void				print_flag_c(t_printf *ptr);
int					colors(char *str, int *count);
void				recu_print_time(unsigned long int time,
		int index, t_printf *ptr);

void				print_f(double nbr, t_printf *ptr);
char				*ft_itoa_base(long long int value, int base);
char				*ft_uitoa_base(unsigned long long int value, int base);

int					ft_putwchar(wchar_t letter);
void				printfwstr(t_printf *ptr, wchar_t *str);
int					strlen_wchar(wchar_t *str);
int					count_significant_bit(int value);
int					count_nb_octet(wchar_t letter);

int					ft_round(double d);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
int					ft_isspace(int c);

#endif
