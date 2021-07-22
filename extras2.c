/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:30:34 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/23 00:30:35 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_3(t_num **stack_a, t_num **stack_b)
{
	int		nb[3];

	nb[0] = (*stack_b)->val;
	nb[1] = (*stack_b)->next->val;
	nb[2] = (*stack_b)->next->next->val;
	//printf("nb[0] : %d\nnb[1] : %d\nnb[2] : %d\n",nb[0],nb[1],nb[2]);
	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[2] > nb[0])
		exec_instructions(stack_a, stack_b, "sb");
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[2] < nb[0])
		exec_instructions(stack_a, stack_b, "rb");
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[2] < nb[0])
		exec_instructions(stack_a, stack_b, "rrb");
	else if (nb[0] > nb[1] && nb[1] > nb[2] && nb[2] < nb[0])
	{
		exec_instructions(stack_a, stack_b, "sb");
		exec_instructions(stack_a, stack_b, "rrb");
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[2] > nb[0])
	{
		exec_instructions(stack_a, stack_b, "sb");
		exec_instructions(stack_a, stack_b, "rb");
	}
}

void	swap_4(t_num **stack_a, t_num **stack_b)
{
	t_num	*low;
	t_roll	roll_low;

	low = get_lowest(*stack_b);
	roll_low = get_nb_rolls(*stack_b, low, 'b');
	put_nb_on_top(roll_low, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	swap_3(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");
}

void	swap_5(t_num **stack_a, t_num **stack_b)
{
	t_num	*low;
	t_num	*great;
	t_roll	roll_low;
	t_roll	roll_great;

	great = get_greatest(*stack_a);
	roll_great = get_nb_rolls(*stack_a, great, 'a');
	put_nb_on_top(roll_great, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	low = get_lowest(*stack_a);
	roll_low = get_nb_rolls(*stack_a, low, 'a');
	put_nb_on_top(roll_low, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
	exec_instructions(stack_a, stack_b, "pa");
	exec_instructions(stack_a, stack_b, "ra");
}

