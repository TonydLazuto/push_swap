/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rolls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 01:12:24 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/07 08:48:06 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*get_lowest(t_num *stack_a)
{
	int		valid;
	t_num	*tmp;
	t_num	*elet;
	int		size;

	tmp = NULL;
	elet = stack_a;
	size = list_length(stack_a);
	while (elet)
	{
		tmp = stack_a;
		valid = 1;
		while (tmp)
		{
			if (elet->val < tmp->val)
				valid++;
			tmp = tmp->next;
		}
		if (valid == size)
			return (elet);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet);
}

t_num	*get_greatest(t_num *stack_a)
{
	int		valid;
	t_num	*tmp;
	t_num	*elet;
	int		size;

	tmp = NULL;
	elet = stack_a;
	size = list_length(stack_a);
	while (elet)
	{
		tmp = stack_a;
		valid = 1;
		while (tmp)
		{
			if (elet->val > tmp->val)
				valid++;
			tmp = tmp->next;
		}
		if (valid == size)
			return (elet);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet);
}

t_roll	get_ins(t_roll roll, t_roll reverse, char select)
{
	if (select == 'a')
	{
		if (roll.pos < reverse.pos)
			roll.ins = "ra";
		else
			reverse.ins = "rra";
	}
	else
	{
		if (roll.pos < reverse.pos)
			roll.ins = "rb";
		else
			reverse.ins = "rrb";
	}
	if (roll.ins)
		return (roll);
	return (reverse);
}

t_roll	get_nb_rolls(t_num *stack, t_num *elet, char select)
{
	t_num	*tmp;
	t_roll	roll;
	t_roll	reverse;
	t_roll	ret;

	init_roll(&roll);
	init_roll(&reverse);
	init_roll(&ret);
	tmp = stack;
	while (tmp->val != elet->val)
	{
		roll.pos++;
		tmp = tmp->next;
	}
	while (elet)
	{
		reverse.pos++;
		elet = elet->next;
	}
	ret	= get_ins(roll, reverse, select);
	return (ret);
}

void	put_nb_on_top(t_roll roll, t_num **stack_a, t_num **stack_b)
{
	while (roll.pos != 0)
	{
		exec_instructions(stack_a, stack_b, roll.ins);
		roll.pos--;
	}
}

