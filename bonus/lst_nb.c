/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:00:57 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/10 08:21:10 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num		*new_nb(int val)
{
	t_num *nb;

	if (!(nb = malloc(sizeof(*nb))))
		return (NULL);
	nb->val = val;
	nb->next = NULL;
	return (nb);
}

t_num		*last_num(t_num *nb)
{
	if (nb == NULL)
		return (NULL);
	while (nb->next != NULL)
		nb = nb->next;
	return (nb);
}

void		push_back(t_num **list, t_num *elet)
{
	t_num	*tmp;

	tmp = *list;
	if (!elet)
		return ;
	if (!*list)
	{
		*list = elet;
		return ;
	}
	tmp = last_num(tmp);
	tmp->next = elet;
}
