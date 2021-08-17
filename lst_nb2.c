/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nb2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:27:14 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/07 09:57:04 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num		*push_back(t_num *list, int val, int num_chunk)
{
	t_num	*elet;
	t_num	*tmp;

	elet = new_nb(val, num_chunk);
	tmp = list;
	if (!elet)
		return (NULL);
	if (!list)
		return (elet);
	tmp = last_num(tmp);
	elet->back = tmp;
	tmp->next = elet;
	return (list);
}

t_num		*push_front(t_num *list, int val, int num_chunk)
{
	t_num	*elet;

	elet = new_nb(val, num_chunk);
	if (!elet)
		return (NULL);
	if (list)
	{
		list->back = elet;
		elet->next = list;
	}
	return (elet);
}

t_num	*pop_back(t_num *list)
{
	t_num	*tmp;
	t_num	*before;

	tmp = list;
	before = list;
	if (!list)
		return (list);
	if (!list->next && !list->back)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	while (tmp->next)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	tmp->back = NULL;
	free(tmp);
	tmp = NULL;
	return (list);
}

t_num	*pop_front(t_num *list)
{
	t_num	*first;

	first = list;
	if (!list)
		return (NULL);
	list = list->next;
	first->next = NULL;
	free(first);
	first = NULL;
	return (list);
}

void	clear_lst(t_num **lst)
{
	while (*lst)
		*lst = pop_front(*lst);
}
