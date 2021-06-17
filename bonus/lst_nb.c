/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:00:57 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/17 17:41:19 by tonyd            ###   ########.fr       */
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
