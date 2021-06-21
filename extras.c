/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:42:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/21 02:21:16 by tonyd            ###   ########.fr       */
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

int		get_lowest(int nb[5])
{
	int	i;
	int	j;
	int valid;

	i = 0;
	while (i < 5)
	{
		j = 0;
		valid = 0;
		while (j < 5)
		{
			//printf("i : %d\nj : %d\nvalid : %d\n",i, j, valid);
			if (i == j)
				j++;
			if (nb[i] < nb[j])
				valid++;
			j++;
		}
		if (valid == 4)
			return (i);
		i++;
	}
	return (--i);
}

void	find_lowest(t_num **stack_a)
{
	t_num	*tmp;
	int		nb[5];
	int		i;
	int		pos;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		nb[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	pos = get_lowest(nb);
	printf("lowest position: %d\n", pos);
}

void	swap_five(t_num **stack_a, t_num **stack_b)
{
	(void)stack_b;
	//t_num *low;
	//t_num *great;
	//t_num *nearest;

	find_lowest(stack_a);
	//great = find_greatest(stack_a);
	//nearest = get_nearest_to_top(low, great);
/*
	exec_instructions(stack_a, stack_b, "pb");
	exec_instructions(stack_a, stack_b, "pb");
	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
	swap_three(stack_a, stack_b);
*/
}
