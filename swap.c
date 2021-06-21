/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 01:12:24 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/21 01:32:03 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push_lowest_nb(t_num **stack_a, t_num **stack_b)
{
	//find_lowest_nb
	lowest = get_lowest_nb(stack_a);
	if (!lowest)
		ft_error(stack_a, stack_b);
	;
}

void	swap(t_num **stack_a, t_num **stack_b)
{
	t_num	*lowest;

	while (*stack_a)
	{
		lowest = push_lowest_nb(stack_a, stack_b);
		pop_lowest_nb(stack_a, lowest);
	}
	while (*stack_b)
	{
		*stack_b = pop_front
	}
}
