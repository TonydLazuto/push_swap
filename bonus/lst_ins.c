/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:17 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/10 08:27:44 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ins		*new_ins(char *str)
{
	t_ins *ins;

	if (!(ins = malloc(sizeof(ins))))
		return (NULL);
	if (!(ins->str = ft_strdup(str)))
		return (NULL);
	ins->next = NULL;
	return (ins);
}

t_ins		*last_ins(t_ins *ins)
{
	if (ins == NULL)
		return (NULL);
	while (ins->next != NULL)
		ins = ins->next;
	return (ins);
}

void		push_back_ins(t_ins **list, t_ins *elet)
{
	t_ins	*tmp;

	tmp = *list;
	if (!elet)
		return ;
	if (!*list)
	{
		*list = elet;
		return ;
	}
	tmp = last_ins(tmp);
	tmp->next = elet;
}
