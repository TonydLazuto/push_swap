/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:30:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/01 20:33:33 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
t_num	*merge(t_num *array_a, t_num *array_b)
{
	t_num	*sorted;

	while (array_a && array_b)
	{
		if (array_a->val > array_b->val)
		{
			sorted = push_back(sorted, array_b->val);
			array_b = pop_front(array_b);
		}
		else
		{
			sorted = push_back(sorted, array_a->val);
			array_a = pop_front(array_a);
		}
	}
	while (array_a)
	{
		sorted = push_back(sorted, array_a->val);
		array_a = pop_front(array_a);
	}
	while (array_b)
	{
		sorted = push_back(sorted, array_b->val);
		array_b = pop_front(array_b);
	}
	return (sorted);
}
t_num	*merge_sort(t_num *stack)
{
	t_num	*array_a;
	t_num	*array_b;

	array_a = NULL;
	array_b = NULL;
	if (list_length(stack) == 1)
		return (stack);
	split_array(&stack, &array_a, &array_b);
	printf("____________________________\n");
	print_nb(array_a);
	printf("____________________________\n");
	print_nb(array_b);
	array_a = merge_sort(array_a);
	array_b = merge_sort(array_b);

	return (merge(array_a, array_b));

	//merge half on stack_b
	//merge stack_a
	//merge stack_b on stack_a
}
*/

/*	t_num	*array_a;
	t_num	*array_b;

	array_a = NULL;
	array_b = NULL;
	split_array(&stack, &array_a, &array_b);
	printf("____________________________\n");
	print_nb(array_a);
	printf("____________________________\n");
	print_nb(array_b);
*/
/*
t_num	*get_pivot(t_num *stack_a) // new stack
{
	t_num	*pivot;

	pivot = stack_a;
	if (stack_a)
	{
		while (pivot->pos != list_length(*stack_a) / 2)
			pivot = pivot->next;
	}
	return (pivot);
}

int		partition(t_num **stack_a, t_num **stack_b, int lb, int ub)
{
	t_num*	pivot;
	int		start;
	int		end;

	pivot = get_pivot(*stack_a);
	start = lb;
	end = ub;
	while (start < end)
	{
		while ((*stack_a)->val < pivot)
		{
			*stack_a = (*stack_a)->next;
			start++;
		}
		*stack_a = pivot->next;
		while (*stack_a > pivot)
		{
		}
	}
}

void	quick_sort(t_num **stack_a, t_num **stack_b, int lb, int ub)
{
	int		pivot_pos;

	if (lb < ub)
	{
		pivot_pos = partition(stack_a, stack_b, lb ,ub);
		//quick_sort(stack_a, stack_b, lb, pivot_pos - 1);
		//quick_sort(stack_a, stack_b, pivot_pos + 1, ub);
	}
}
*/
void	myquick(t_num **stack_a, t_num **stack_b)
{
	set_num_pos(stack_a);
	print_nb(*stack_a);
	//quick_sort(stack_a, stack_b, 1, list_length(*stack_a) - 1);
}

