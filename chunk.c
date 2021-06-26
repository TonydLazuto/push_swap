/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:30:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/26 09:32:21 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk5(t_num **stack_a, t_num **stack_b, int ac)
{
	t_num	*low;
	t_roll	roll_low;
	t_roll	roll_great;

	while (ac / 5)
	{
		low = *stack_a;
		low = get_lowest(*stack_a, low);
		roll_low = get_nb_rolls(*stack_a, low);
		put_nb_on_top(roll_low, stack_a, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
	}
	while (*stack_b)
		exec_instructions(stack_a, stack_b, "pa");	
}

/*
void	chun11(t_num **stack_a, t_num **stack_b, int ac)
{
}
*/
