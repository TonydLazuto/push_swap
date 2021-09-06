/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:17 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/12 09:56:14 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ins	*new_ins(char *str)
{
	t_ins	*ins;

	ins = malloc(sizeof(ins));
	if (!ins)
		return (NULL);
	ins->str = ft_strdup(str);
	if (!(ins->str))
		return (NULL);
	ins->next = NULL;
	return (ins);
}

t_ins	*last_ins(t_ins *ins)
{
	if (!ins)
		return (NULL);
	while (ins->next)
		ins = ins->next;
	return (ins);
}

t_ins	*push_back_ins(t_ins *list, char *line)
{
	t_ins	*tmp;
	t_ins	*elet;

	tmp = list;
	elet = new_ins(line);
	if (!elet)
		return (NULL);
	if (!list)
		return (elet);
	tmp = last_ins(tmp);
	tmp->next = elet;
	return (list);
}
