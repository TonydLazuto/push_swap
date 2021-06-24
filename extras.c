/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:42:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/24 14:47:14 by tonyd            ###   ########.fr       */
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
/*
void	swap_five(t_num **stack_a, t_num **stack_b)
{
	(void)stack_b;
	//t_num *low;
	//t_num *great;
	//t_num *nearest;

	exec_instructions(stack_a, stack_b, "pb");
	exec_instructions(stack_a, stack_b, "pb");
	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
	swap_three(stack_a, stack_b);
*/
}
