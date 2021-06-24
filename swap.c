/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 01:12:24 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/24 20:51:59 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*get_lowest(t_num *stack_a, t_num *elet)
{
	int		valid;
	t_num	*tmp;
	int		size;

	tmp = NULL;
	size = list_length(stack_a);
	while (elet)
	{
		tmp = stack_a;
		valid = 1;
		while (tmp)
		{
			if (elet->val < tmp->val)
				valid++;
			tmp = tmp->next;
		}
		//printf("valid : %d\nelet : %d\nsize : %d\n",valid, elet->val, size);
		if (valid == size)
			return (elet);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet);
}
t_num	*get_greatest(t_num *stack_a, t_num *elet)
{
	int		valid;
	t_num	*tmp;
	int		size;

	tmp = NULL;
	size = list_length(stack_a);
	while (elet)
	{
		tmp = stack_a;
		valid = 1;
		while (tmp)
		{
			if (elet->val > tmp->val)
				valid++;
			tmp = tmp->next;
		}
		if (valid == size)
			return (elet);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet);
}

t_roll	get_nb_rolls(t_num *stack_a, t_num *elet)
{
	t_num	*tmp;
	t_roll	ra;
	t_roll	rra;

	init_roll(&ra);
	init_roll(&rra);
	tmp = stack_a;
	while (tmp->val != elet->val)
	{
		ra.nb++;
		tmp = tmp->next;
	}
	while (elet)
	{
		rra.nb++;
		elet = elet->next;
	}
	if (ra.nb < rra.nb)
	{
		ra.ins = "ra";
		return (ra);
	}
	rra.ins = "rra";
	return (rra);
}

void	pop_xtrms(t_num **stack_a, t_num **stack_b)
{
	t_num	*elet;
	t_num	*elet2;
	t_roll	roll;

	elet = *stack_a;
	elet2 = *stack_a;
	elet = get_lowest(*stack_a, elet);
	roll = get_nb_rolls(*stack_a, elet);
	//printf("lowest number : %d\nnb : %d\nins : %s\n",
				//elet->val, roll.nb, roll.ins);
	elet2 = get_greatest(*stack_a, elet2);
	roll = get_nb_rolls(*stack_a, elet2);
	//printf("gtest number : %d\nnb : %d\nins : %s\n",
				//elet2->val, roll.nb, roll.ins);
	print_nb(*stack_a);
}
