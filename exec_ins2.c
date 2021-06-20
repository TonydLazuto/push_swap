/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:45:02 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/20 09:54:06 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num		*switch_nb(t_num *cur, t_num *other_stack, const char *ins)
{
	int		val;

	if (ins)
		print_const(ins, 1);
	if (cur && cur->next) // condition du bonus. pas utile ici pour les 4 fonctions
	{
		val = cur->val;
		cur->val = cur->next->val;
		cur->next->val = val;
	}
	return (cur);
}

void		push_nb(t_num **cur, t_num **other_stack, const char *ins)
{
	t_num	*elet;

	elet = NULL;
	if (ins)
		print_const(ins, 1);
	if (*other_stack)
	{
		*cur = push_front(*cur, (*other_stack)->val);
		if (!*cur)
			ft_error(cur, other_stack); 
		*other_stack = pop_front(*other_stack);
	}
}

t_num		*roll_stack(t_num *cur, t_num *other_stack, const char *ins)
{
	if (ins)
		print_const(ins, 1);
	if (cur && cur->next)
	{
		cur = push_back(cur, cur->val);
		if (!cur)
			ft_error(&cur, &other_stack);
		cur = pop_front(cur);
	}
	return (cur);
}

t_num		*reverse_roll_stack(t_num *cur, t_num *other_stack, const char *ins)
{
	if (ins)
		print_const(ins, 1);
	if (cur && cur->next)
	{
		cur = push_front(cur, last_num(cur)->val);
		if (!cur)
			ft_error(&cur, &other_stack);
		cur = pop_back(cur);
	}
	return (cur);
}
