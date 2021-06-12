/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nb2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:27:14 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/12 08:39:17 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num	*pop_back(t_num *list)
{
	t_num	*tmp;
	t_num	*before;

	tmp = list;
	before = list;
	if (!list)
		return (list);
	if (list->next == NULL)
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

t_num	*pop_back(t_num *list)
{
	t_num	*elet;

	elet = malloc(sizeof(*elet));
	if (!elet)
		return (NULL);
	if (!list)
		return (list);
	elet = list->next;
	free(list);
	list = NULL;
	return (elet);
}
