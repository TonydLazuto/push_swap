/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:44:43 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/21 11:44:45 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		switch_pos(t_num **stack_a)
{
	int tmp;

	tmp = (*stack_a)->pos;
	(*stack_a)->pos = (*stack_a)->next->pos;
	(*stack_a)->next->pos = tmp;
}

int			check_switch_b(t_num **stack_b)
{
	if (*stack_b)
	{
		if ((*stack_b)->next)
		{
			if ((*stack_b)->val < (*stack_b)->next->val
			&& (*stack_b)->true_pos == -1
			&& (*stack_b)->next->true_pos == -1)
				return (1);
		}
	}
	return (0);
}

int			check_switch_a(t_num **stack_a)
{
	if ((*stack_a)->next)
	{
		if ((*stack_a)->val > (*stack_a)->next->val
		&& (*stack_a)->true_pos == -1
		&& (*stack_a)->next->true_pos == -1)
			return (1);
	}
	return (0);
}

void		switch2(t_num **stack_a, t_num **stack_b,
				int i, int range)
{
	if (check_switch_b(stack_b))
	{
		if (check_switch_a(stack_a) && i + 1 <= range)
			exec_instructions(stack_a, stack_b, "ss");
		else
			exec_instructions(stack_a, stack_b, "sb");
	}
	/*
	if (check_switch_b(stack_b))
	{
		printf("sb\n(*stack_a)->val : %d\n", (*stack_a)->val);
		exec_instructions(stack_a, stack_b, "sb");
	}
	*/
}

// attention aux fuites memoire du roll_stack() ft_error(cur, other_stack)
// cur est en faite sub et stack_a ne sera pas vidée en cas d'erreur
void		fill_stack_b(t_num **stack_a, t_num **stack_b,
				t_num *cpy_pivot, int range)
{
	int		i;

	i = 0;
	while (i <= range)
	{
		switch2(stack_a, stack_b, i, range);
		if ((*stack_a)->val <= cpy_pivot->val)
		{
			exec_instructions(stack_a, stack_b, "pb");
			//sub = pop_front(sub);
		}
		else
		{
			exec_instructions(stack_a, stack_b, "ra");
			//sub = roll_stack(sub, *stack_b, "");
		}
		i++;
	}
	
}