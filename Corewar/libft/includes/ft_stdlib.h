/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:34:03 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:34:04 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long int value, int base);
char				*ft_uitoa_base(unsigned long long int value, int base);

#endif
