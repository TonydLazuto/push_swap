/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:00:57 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/05 15:00:07 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num		*new_nb(int val)
{
	t_num *elet;

	elet = malloc(sizeof(*elet));
	if (!elet)
		return (NULL);
	elet->val = val;
	elet->next = NULL;
	elet->back = NULL;
	return (elet);
}

t_num		*begin_num(t_num *elet)
{
	if (!elet)
		return (NULL);
	while (elet->back)
		elet = elet->back;
	return (elet);
}

t_num		*last_num(t_num *elet) //check_half_length for go->next or go->back
{
	if (!elet)
		return (NULL);
	while (elet->next)
		elet = elet->next;
	return (elet);
}

int			list_length(t_num *lst)
{
	int		size;

	size = 0;
	if (lst)
	{
		while (lst)
		{
			++size;
			lst = lst->next;
		}
	}
	return (size);
}

int			is_point_in_list(t_num *nb, int val)
{
	t_num *elet;

	elet = nb;
	while (elet)
	{
		if (elet->val == val)
			return (1);
		elet = elet->next;
	}
	return (0);
}
