/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:46:02 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:48:38 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H
# include <stdbool.h>
# include <stdlib.h>

typedef struct				s_lst_elem__
{
	void					*data;
	struct s_lst_elem__		*next;
	struct s_lst_elem__		*prev;
}							t_lst_elem__;

typedef struct				s_lst
{
	t_lst_elem__			*head;
	t_lst_elem__			*tail;
}							t_lst;

/*
** allocation / deletion
*/
t_lst						*ft_lst_new(void);
void						*ft_lst_pop_back(t_lst *lst);
void						*ft_lst_pop_front(t_lst *lst);
void						ft_lst_del(t_lst *lst, void (*delfn)(void*));
void						ft_lst_push_back(t_lst *lst, void *data);
void						ft_lst_push_front(t_lst *lst, void *data);
t_lst						*ft_lst_slice(t_lst *lst, int begin, int end);
t_lst						*ft_lst_map(t_lst *lst, void *(*f)(void *data));
t_lst						*ft_lst_cpy(t_lst *lst, void *(*f)(void *data));

/*
** basic tools
*/
int							ft_lst_len(t_lst *lst);
void						*ft_lst_get(t_lst *lst, int index);
void						ft_lst_insert(t_lst *lst, void *data, int index);
void						ft_lst_insert_after(t_lst *lst, void *data,
																void *context);
void						ft_lst_insert_before(t_lst *lst, void *data,
																void *context);
int							ft_lst_get_index(t_lst *lst, void *data);
int							ft_lst_count(t_lst *lst, bool (*fn)(void *data));
void						*ft_lst_to_arr(t_lst *lst, size_t size);
void						ft_lst_print(t_lst *lst,
							int	(*p_fn)(void *data), char *sep);
void						*ft_lst_find(t_lst *lst,
							bool (*f)(void *data, void *context),
																void *context);
void						ft_lst_remove(t_lst *lst, bool (*cmp_fn)
																(void*, void*),
							void *context, void (*del_fn) (void*));

/*
** iteration
*/
void						ft_lst_iter_simple(t_lst *lst,
														void (*f)(void *data));
void						ft_lst_iter(t_lst *lst,
							void (*f)(void *data, void *context),
																void *context);

/*
** PRIVATE
*/
t_lst_elem__				*ft_lst_create_elem__(void *data);
t_lst_elem__				*ft_lst_get_elem__(t_lst *lst, int index);
void						ft_lst_link__(t_lst_elem__ *elem1,
														t_lst_elem__ *elem2);
void						ft_lst_link_all__(t_lst_elem__ *elem1,
									t_lst_elem__ *elem2, t_lst_elem__ *elem3);
void						ft_lst_del_elem__(t_lst *lst, t_lst_elem__ *elem,
							void (*delfn)(void*));
void						ft_lst_iter_elem__(t_lst *lst,
							void (*f)(t_lst_elem__ *elem));

#endif
