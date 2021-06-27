/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rolls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 01:12:24 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/26 17:43:41 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*get_lowest(t_num *stack_a, t_num *elet)
{
	int		valid;
	t_num	*tmp;
	int		size;

	tmp = NULL;
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
		//printf("valid : %d\nelet : %d\nsize : %d\n",valid, elet->val, size);
		if (valid == size)
			return (elet);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet);
}
t_num	*get_greatest(t_num *stack_a, t_num *elet)
{
	int		valid;
	t_num	*tmp;
	int		size;

	tmp = NULL;
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

t_roll	get_nb_rolls(t_num *stack_a, t_num *elet)
{
	t_num	*tmp;
	t_roll	ra;
	t_roll	rra;

	init_roll(&ra);
	init_roll(&rra);
	tmp = stack_a;
	while (tmp->val != elet->val)
	{
		ra.pos++;
		tmp = tmp->next;
	}
	while (elet)
	{
		rra.pos++;
		elet = elet->next;
	}
	if (ra.pos < rra.pos)
	{
		ra.ins = "ra";
		return (ra);
	}
	rra.ins = "rra";
	return (rra);
}

void	put_nb_on_top(t_roll roll, t_num **stack_a, t_num **stack_b)
{
	while (roll.pos != 0)
	{
		exec_instructions(stack_a, stack_b, roll.ins);
		roll.pos--;
	}
}

