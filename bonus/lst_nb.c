/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:00:57 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/12 08:54:10 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num		*new_nb(int val)
{
	t_num *elet;

	elet = malloc(sizeof(*elet));
	if (!elet)
		return (NULL);
	elet->val = val;
	elet->next = NULL;
	return (elet);
}

t_num		*last_num(t_num *elet)
{
	if (!elet)
		return (NULL);
	while (elet->next)
		elet = elet->next;
	return (elet);
}

t_num		*push_back(t_num *list, int val)
{
	t_num	*elet;
	t_num	*tmp;

	elet = new_nb(val);
	tmp = list;
	if (!elet)
		return (NULL);
	elet->next = NULL;
	if (!list)
		return (elet);
	tmp = last_num(tmp);
	tmp->next = elet;
	return (list);
}

t_num		*push_front(t_num *list, int val)
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
