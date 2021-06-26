/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:42:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/26 11:50:53 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_num **stack_a, t_num **stack_b)
{
	int		nb[2];

	nb[0] = (*stack_a)->val;
	nb[1] = (*stack_a)->next->val;
	if (nb[0] > nb[1])
		exec_instructions(stack_a, stack_b, "sa");
}

void	swap_three(t_num **stack_a, t_num **stack_b)
{
	int		nb[3];

	nb[0] = (*stack_a)->val;
	nb[1] = (*stack_a)->next->val;
	nb[2] = (*stack_a)->next->next->val;
	//printf("nb[0] : %d\nnb[1] : %d\nnb[2] : %d\n",nb[0],nb[1],nb[2]);
	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[2] > nb[0])
		exec_instructions(stack_a, stack_b, "sa");
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[2] < nb[0])
		exec_instructions(stack_a, stack_b, "ra");
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[2] < nb[0])
		exec_instructions(stack_a, stack_b, "rra");
	else if (nb[0] > nb[1] && nb[1] > nb[2] && nb[2] < nb[0])
	{
		exec_instructions(stack_a, stack_b, "sa");
		exec_instructions(stack_a, stack_b, "rra");
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[2] > nb[0])
	{
		exec_instructions(stack_a, stack_b, "sa");
		exec_instructions(stack_a, stack_b, "ra");
	}
}

void	swap_four(t_num **stack_a, t_num **stack_b)
{
	t_num	*low;
	t_roll	roll_low;

	low = *stack_a;

	low = get_lowest(*stack_a, low);
	roll_low = get_nb_rolls(*stack_a, low);
	put_nb_on_top(roll_low, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
}

void	swap_five(t_num **stack_a, t_num **stack_b)
{
	t_num	*low;
	t_num	*great;
	t_roll	roll_low;
	t_roll	roll_great;

	great = *stack_a;

	great = get_greatest(*stack_a, great);
	roll_great = get_nb_rolls(*stack_a, great);
	put_nb_on_top(roll_great, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	low = *stack_a;

	low = get_lowest(*stack_a, low);
	roll_low = get_nb_rolls(*stack_a, low);
	put_nb_on_top(roll_low, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
	exec_instructions(stack_a, stack_b, "pa");
	exec_instructions(stack_a, stack_b, "ra");
}

