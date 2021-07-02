/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:30:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/02 19:22:09 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * Here, I will find the pivot which is
 * the middle value in the stack.
 * Thereby, the precision of the quicksort algorithm
 * will be more like O=nlog(n) than O=(n square)
 */

//unuse splitarray
void	split_array(t_num **stack, t_num **array_a, t_num **array_b)
{
	int		i;
	int		half;
	t_num	*sa;

	i = 0;
	sa = *stack;
	half = list_length(*stack) / 2;
	while (i < half)
	{
		*array_a = push_back(*array_a, sa->val);
		sa = sa->next;
		i++;
	}
	while (sa)
	{
		*array_b = push_back(*array_b, sa->val);
		sa = sa->next;
	}
}

void		ft_swap(t_num **stack_a, t_num **stack_b, t_num **start, t_num **end)
{
	t_roll r_start;
	t_roll r_end;

	r_start = get_nb_rolls(*stack_a, *start);
	r_end = get_nb_rolls(*stack_a, *end);
	if (r_start.pos < r_end.pos)
	{
		put_nb_on_top(r_start, start, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
		put_nb_on_top(r_end, end, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
	}
	else 
	{
		put_nb_on_top(r_end, end, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
		put_nb_on_top(r_start, start, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
	}
}

t_num		*partition(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num*	pivot;
	t_num*	start;
	t_num*	end;

	print_nb(*stack_a);
	printf("____________________________\n");
	pivot = get_pivot(stack_a, stack_b, min, max);
	printf("pivot->val : %d\n", pivot->val);
	start = go_position(min, *stack_a);
	end = go_position(max, *stack_a);
	int i = 0;
	//while (start->pos < end->pos)
	/*
	while (i < 1)
	{
		while (start->val < pivot->val)
			start = start->next;
		printf("start->val : %d\n", start->val);
		while (end->val > pivot->val)
			end = end->back;
		printf("end->val : %d\n", end->val);
		printf("start->pos : %d\nend->pos : %d\n", start->pos, end->pos);
	printf("____________________________\n");
		if (start->pos < end->pos)
			ft_swap(stack_a, stack_b, &start, &end);
	i++;
	}
	*/
	return (end);
}

void		quick_sort(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num	*pivot_pos;

	if (min < max)
	{
		set_num_pos(stack_a);
		pivot_pos = partition(stack_a, stack_b, min ,max);
		//quick_sort(stack_a, stack_b, min, pivot_pos - 1);
		//quick_sort(stack_a, stack_b, pivot_pos + 1, max);
	}
}
// find middle value
void		myquick(t_num **stack_a, t_num **stack_b)
{
	quick_sort(stack_a, stack_b, 0, list_length(*stack_a) - 1);
}

