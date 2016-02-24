/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 21:53:27 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/24 23:08:33 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_list
{
	char			*s;
	char			*conv;
	char			flag;
	int				tmdc;
	int				prec;
	struct s_list	*next;
}					t_l;

int					ft_printf(const char *format, ...);

#endif
