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

t_num	*get_lowest_val(t_num *stack_a)
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

t_num	*get_highest_val(t_num *stack_a)
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

t_roll	get_ins(int roll, int reverse, char select, t_roll ret)
{
	if (roll < reverse)
		ret.pos = roll;
	else
		ret.pos = reverse;
	if (select == 'a')
	{
		if (roll < reverse)
			ret.ins = "ra";
		else
			ret.ins = "rra";
	}
	else
	{
		if (roll < reverse)
			ret.ins = "rb";
		else
			ret.ins = "rrb";
	}
	return (ret);
}

t_roll	get_nb_rolls(t_num *stack, t_num *elet, char select_stack)
{
	t_num	*tmp;
	int		roll;
	int		reverse;
	t_roll	ret;

	roll = 0;
	reverse = 0;
	init_roll(&ret);
	tmp = stack;
	while (tmp->val != elet->val)
	{
		roll++;
		tmp = tmp->next;
	}
	while (elet)
	{
		reverse++;
		elet = elet->next;
	}
	ret = get_ins(roll, reverse, select_stack, ret);
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
