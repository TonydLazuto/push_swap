/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nb2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:27:14 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/13 01:56:23 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num	*push_back(t_num *list, int val)
{
	t_num	*elet;
	t_num	*tmp;

	elet = new_nb(val);
	tmp = list;
	if (!elet)
		return (NULL);
	if (!list)
		return (elet);
	tmp = last_num(tmp);
	tmp->next = elet;
	return (list);
}

t_num	*push_front(t_num *list, int val)
{
	t_num	*elet;

	elet = new_nb(val);
	if (!elet)
		return (NULL);
	if (!list)
		elet->next = NULL;
	else
		elet->next = list;
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
	if (!list->next)
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
	free(first);
	first = NULL;
	return (list);
}
