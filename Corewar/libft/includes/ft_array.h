/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:52:14 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:54:37 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H
# include <libft.h>
# include <stdbool.h>

/*
** allocation / deletion / addition
*/
void			*ft_arr_cpy(void *arr);
void			*ft_arr_new(size_t size);
void			ft_arr_push(void *arr_, void *elem);
void			ft_arr_del(void *arr, void (*delfn)(void *data));

/*
** basic tools
*/
size_t			ft_arr_len(void *arr_);
void			ft_arr_rev(void *arr_);
void			ft_arr_print(void *arr_, int(*p_fn)(void *data));
int				ft_arr_count(void *arr_, bool (*fn)(void *data));
int				ft_arr_get_index(void *arr_,
	bool (*cmp_fn)(void *data, void *context), void *context);

/*
** iteration
*/
void			ft_arr_iter_simple(void *arr_, void(*f)(void *data));
void			ft_arr_iter(void *arr_, void(*f)(void *elem, void *context),
	void *context);

#endif
