/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:08:52 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/26 10:08:54 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	roll_same(t_num **stack_a, t_num **stack_b, t_roll r[2])
{
	const char *ins;

	if (ft_strlen(r[0].ins) == 3)
		ins = "rrr";
	else
		ins = "rr";	
	while (r[0].pos > 0 && r[1].pos > 0)
	{
		exec_instructions(stack_a, stack_b, ins);
		r[0].pos--;
		r[1].pos--;
	}
	while (r[0].pos > 0)
	{
		exec_instructions(stack_a, stack_b, r[0].ins);
		r[0].pos--;
	}
	while (r[1].pos > 0)
	{
		exec_instructions(stack_a, stack_b, r[1].ins);
		r[1].pos--;
	}
}

void	get_dist(t_num **stack_a, t_num **stack_b,
			t_num *lowest_a, t_num *highest_b)
{
	t_roll	r[2];

	r[0] = get_nb_rolls(*stack_a, lowest_a, 'a');
	r[1] = get_nb_rolls(*stack_b, highest_b, 'b');

	if (ft_strlen(r[0].ins) == ft_strlen(r[1].ins))
	{
		roll_same(stack_a, stack_b, r);
	}
	else
	{
		//roll_one();
	}
	
}

void	get_extremes_val(t_num **stack_a, t_num **stack_b,
				t_num *pivot, int range)
{
	t_num	*highest_b;
	t_num	*lowest_a;
	t_num	*sub_a;

	sub_a = get_sub_lst(stack_a, (*stack_a)->pos, (*stack_a)->pos + range);
	highest_b = get_highest_val(*stack_b);
	lowest_a = get_lowest_val(sub_a);

	get_dist(stack_a, stack_b, lowest_a, highest_b);
	/*
	if ((*stack_a)->val <= pivot->val)
		exec_instructions(stack_a, stack_b, "pb");
	else
		exec_instructions(stack_a, stack_b, "ra");	
	*/
}

void	fill_and_sort(t_num **stack_a, t_num **stack_b,
				t_num *pivot, int range)
{
	int		i;
	int		last_val;

	i = 0;
	last_val = last_num(*stack_a)->val;
	while (i <= range)
	{
		if (i > 1)
			get_extremes_val(stack_a, stack_b, pivot, range);
		else
		{
			if ((*stack_a)->val <= pivot->val)
				exec_instructions(stack_a, stack_b, "pb");
			else
				exec_instructions(stack_a, stack_b, "ra");	
		}
		i++;
	}
}