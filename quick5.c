/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:08:49 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/22 23:08:52 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * get sublist from the *stack_a to cur_min in paramaters
 * and then find the tmp pivot.
 **/

t_num	*get_sub_tmp_pivot(t_num **stack_a, t_roll r)
{
	t_num	*cpy;
	t_num	*sub;
	int		i;
	int		direction;

	i = -1;
	sub = NULL;
	cpy = *stack_a;
	direction = 1;
	if (ft_strlen(r.ins) == 3)
	{
		cpy = last_num(*stack_a);
		direction = -1;
	}
	while (r.pos != 0)
	{
		sub = push_back(sub, cpy->val, ++i, cpy->true_pos);
		if (direction > 0)
			cpy = cpy->next;
		else
			cpy = cpy->back;
		r.pos--;
	}
	return (sub);
}

void	empty_stack_b_go_min(t_num **stack_a, t_num **stack_b)
{
	while(*stack_b)
	{
		exec_instructions(stack_a, stack_b, "pa");
		if (check_switch_a(stack_a))
		{
			exec_instructions(stack_a, stack_b, "sa");
			switch_pos(stack_a);
		}
	}
}

void	roll_to_min(t_num **stack_a, t_num **stack_b,
				t_roll r, t_num *tmp_pivot)
{
	while (r.pos != 0)
	{	
		if (check_switch_a(stack_a))
		{
			exec_instructions(stack_a, stack_b, "sa");
			switch_pos(stack_a);
		}
		exec_instructions(stack_a, stack_b, "ra");
		r.pos--;
	}
}
void	reverse_to_min(t_num **stack_a, t_num **stack_b,
				t_roll r, t_num *tmp_pivot)
{
	exec_instructions(stack_a, stack_b, "rra");
	r.pos--;
	exec_instructions(stack_a, stack_b, "rra");
	r.pos--;
	while (r.pos != 0)
	{		
		if (check_switch_a(stack_a))
		{
			exec_instructions(stack_a, stack_b, "sa");
			switch_pos(stack_a);
		}
		exec_instructions(stack_a, stack_b, "rra");
		r.pos--;
	}
}

void	go_to_min2(t_num **stack_a, t_num **stack_b,	
				t_roll r, t_num *tmp_pivot)
{
	if (ft_strlen(r.ins) == 2)
		roll_to_min(stack_a, stack_b, r, tmp_pivot);
	else
		reverse_to_min(stack_a, stack_b, r, tmp_pivot);
	if (check_switch_a(stack_a))
		exec_instructions(stack_a, stack_b, "sa");
}