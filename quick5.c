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

void		switch3(t_num **stack_a, t_num **stack_b)
{
	int		nb[3];
	t_num	*cpy;
	
	cpy = *stack_a;
	nb[0] = (*stack_a)->val;
	nb[1] = (*stack_a)->next->val;
	nb[2] = (*stack_a)->next->next->val;
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

void		switch4(t_num **stack_a, t_num **stack_b)
{
}

void	check_switch(t_num **stack_a, t_num **stack_b)
{
	t_num	*cpy;
	int		i;

	i = 1;
	cpy = *stack_a;
	while (i <= 5 && cpy)
	{
		if (!check_switch_a(&cpy))
			break ;
		i++;
		cpy = cpy->next;
	}
	if (i == 2)
		switch2(stack_a, stack_b);
	if (i == 3)
		switch3(stack_a, stack_b);
	if (i == 4)
		switch4(stack_a, stack_b);
}