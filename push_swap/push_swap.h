/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:47:48 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/02 08:49:30 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_list
{
	int				val;
	struct s_list	*next;
}					t_list;

typedef struct		s_all
{
	t_list			*a;
	t_list			*b;
	int				size;
	char			dec;
}					t_all;

t_list				*create_new(int val);
int					add_elem(t_list **list, t_list *node);
int					del_elem(t_list **list);
int					del_list(t_list **list);
int					swap_elems(t_list **list, char c, int d);
int					push_elem(t_list **list_a, t_list **b, char c, int d);
int					rotate(t_list **list, char c, int d);
int					rev_rotate(t_list **list, char c, int d);
int					print_list(t_list *list);

t_list				*parse(char **argv, int *size);
void				algo(t_all *all);
int					issorted(t_list *list);
int					search_min(t_list *l);
int					search_max(t_list *l);

#endif
