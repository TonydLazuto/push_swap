/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:45:02 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/12 11:37:12 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num		*switch_nb(t_num *cur, t_num *other_stack, t_ins *ins)
{
	int		val;

	if (cur && cur->next)
	{
		val = cur->val;
		cur->val = cur->next->val;
		cur->next->val = val;
	}
	else
		ft_ko(&cur, &other_stack, ins);
	return (cur);
}

void		push_nb(t_num **cur, t_num **other_stack, t_ins *ins)
{
	t_num	*elet;

	elet = NULL;
	if (*other_stack)
	{
		*cur = push_front(*cur, (*other_stack)->val);
		if (!*cur)
			ft_exit(cur, other_stack, ins);
		*other_stack = pop_front(*other_stack);
		if (!*other_stack)
			ft_exit(cur, other_stack, ins);
	}
	else
		ft_ko(cur, other_stack, ins);
}

t_num	*roll_stack(t_num *cur, t_num *other_stack, t_ins *ins)
{
	if (cur && cur->next)
	{
		cur = push_back(cur, cur->val);
		if (!cur)
			ft_exit(&cur, &other_stack, ins);
		cur = pop_front(cur);
		if (!cur)
			ft_exit(&cur, &other_stack, ins);
	}
	else
		ft_ko(&cur, &other_stack, ins);
	return (cur);
}

t_num	*reverse_roll_stack(t_num *cur, t_num *other_stack, t_ins *ins)
{
	if (cur && cur->next)
	{
		cur = push_front(cur, last_num(cur)->val);
		if (!cur)
			ft_exit(&cur, &other_stack, ins);
		cur = pop_back(cur);
	}
	else
		ft_ko(&cur, &other_stack, ins);
	return (cur);
}
