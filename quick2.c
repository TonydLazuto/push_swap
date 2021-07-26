/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:58:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/24 18:58:09 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void		chekc_both_stack(t_num **stack_a, t_num **stack_b,
				t_num *pivot)
{
	if ((*stack_a)->val <= pivot->val)
	{
		exec_instructions(stack_a, stack_b, "pb");
	}
	else
	{
		exec_instructions(stack_a, stack_b, "ra");
	}
}
void		fill_stack(t_num **stack_a, t_num **stack_b,
				t_num *pivot, int range)
{
	int	i;
	int half;

	i = 0;
	half = list_length(*stack_a) / 2;
	while (i < half)
	{
		if (i > 1)
		{
			chekc_both_stack(stack_a, stack_b, pivot);
		}
		else
		{
			if ((*stack_a)->val <= pivot->val)
				exec_instructions(stack_a, stack_b, "pb");
			else
				exec_instructions(stack_a, stack_b, "ra");
			i++;
		}
	}
}