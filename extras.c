/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:42:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/20 08:56:02 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(int *nb)
{
	if (nb[0] > nb[1])
		ft_putendl_fd("sa", 1);
	else if (nb[0] == nb[1])
		ft_error(NULL, NULL, nb);
}

void	swap_three(int *nb, t_num **stack_a, t_num **stack_b)
{
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

void	swap_five(int *nb, t_num **stack_a, t_num **stack_b)
{
	int	stack_b1;
	int	stack_b2;

	stack_b1 = nb[3];
	stack_b2 = nb[4];
	swap_three(nb, stack_a, stack_b);
}
