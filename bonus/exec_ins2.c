/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:45:02 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/11 12:51:38 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num		*switch_nb(t_num *cur, t_num *other_stack, t_ins *ins)
{
	t_num	*elet;
	t_num	*suppr;

	elet = NULL;
	suppr = NULL;
	if (cur && cur->next)
	{
		suppr = cur->next;
		cur->next = cur->next->next;

		elet = new_nb(cur->next->val);
		if (!elet)
			ft_exit(&cur, &other_stack, ins);
		newlst->next = cur;

		free(suppr);
		suppr = NULL;
	}
	else
		ft_exit(&cur, &other_stack, ins);
	return (elet);
}

void		push_nb(t_num **cur, t_num **other_stack, t_ins *ins)
{
	t_num	*elet;
	t_num	*suppr;

	suppr = NULL;
	elet = NULL;
	if (other_stack)
	{
		suppr = *other_stack;
		elet = new_nb(other_stack->val);
		if (!elet)
			ft_exit(cur, other_stack, ins);
		*other_stack = (*other_stack)->next;
		free(suppr);
		suppr = NULL;
		if (cur)
			elet->next = cur;
		cur = elet;
	}
	else
		ft_exit(cur, other_stack, ins);
}

t_num	*roll_stack(t_num *cur, t_num *other_stack, t_ins *ins)
{
}

t_num	*reverse_roll_stack(t_num *cur, t_num *other_stack, t_ins *ins)
{
}
