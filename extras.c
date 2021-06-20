/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:42:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/20 09:53:17 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_num **stack_a, t_num **stack_b)
{
	int		nb1;
	int		nb2;

	nb1 = (*stack_a)->val;
	nb2 = (*stack_a)->next->val;
	if (nb1 > nb2)
		exec_instructions(stack_a, stack_b, "sa");
}

void	swap_three(t_num **stack_a, t_num **stack_b)
{
	int		nb1;
	int		nb2;
	int		nb3;

	nb1 = (*stack_a)->val;
	nb2 = (*stack_a)->next->val;
	nb3 = (*stack_a)->next->next->val;
	//printf("nb1 : %d\nnb2 : %d\nnb3 : %d\n",nb1,nb2,nb3);
	if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
		exec_instructions(stack_a, stack_b, "sa");
	else if (nb1 > nb2 && nb2 < nb3 && nb3 < nb1)
		exec_instructions(stack_a, stack_b, "ra");
	else if (nb1 < nb2 && nb2 > nb3 && nb3 < nb1)
		exec_instructions(stack_a, stack_b, "rra");
	else if (nb1 > nb2 && nb2 > nb3 && nb3 < nb1)
	{
		exec_instructions(stack_a, stack_b, "sa");
		exec_instructions(stack_a, stack_b, "rra");
	}
	else if (nb1 < nb2 && nb2 > nb3 && nb3 > nb1)
	{
		exec_instructions(stack_a, stack_b, "sa");
		exec_instructions(stack_a, stack_b, "ra");
	}
}

void	swap_five(t_num **stack_a, t_num **stack_b)
{
	*stack_b = new_nb((*stack_a)->val);
	if (!stack_b)
		ft_exit(stack_a, stack_b);
	swap_three(stack_a, stack_b);
}
