/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:45:02 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/06 20:40:59 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num		*switch_nb(t_num *cur, const char *ins)
{
	int		val;
	int		num_chunk;

	if (ins)
		print_const(ins, 1);
	if (cur && cur->next)
	{
		num_chunk = cur->num_chunk;
		cur->num_chunk = cur->next->num_chunk;
		cur->next->num_chunk = num_chunk;
		val = cur->val;
		cur->val = cur->next->val;
		cur->next->val = val;
	}
	return (cur);
}

void		push_nb(t_num **cur, t_num **other_stack, const char *ins)
{
	if (ins)
		print_const(ins, 1);
	if (*other_stack)
	{
		*cur = push_front(*cur, (*other_stack)->val, (*other_stack)->num_chunk);
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
		cur = push_back(cur, cur->val, cur->num_chunk);
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
		cur = push_front(cur, last_num(cur)->val, last_num(cur)->num_chunk);
		if (!cur)
			ft_error(&cur, &other_stack);
		cur = pop_back(cur);
	}
	return (cur);
}
