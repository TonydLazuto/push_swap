/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:30:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/27 10:17:47 by tonyd            ###   ########.fr       */
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

void	mymerge(t_num **stack_a, t_num **stack_b)
{
	t_num *sorted1;
	t_num *sorted2;

	sorted1 = NULL;
	sorted2 = NULL;
	split_array(stack_a, &sorted1, &sorted2);
	(void)stack_b;
	sorted1 = merge_sort(sorted1);
	print_nb(sorted1);
}

/*
void	chunk(t_num **stack_a, t_num **stack_b, int ac)
{
	int	half;
	int	min_chunk;
	int	max_chunk;

	t_num	*low;
	t_num	*great;
	t_roll	roll_low;
	t_roll	roll_great;

	half = ac / 2;

	min_chunk = 0;
	max_chunk = 20;

	while (*stack_a)
	{

	}
	great = *stack_a;

	great = get_greatest(*stack_a, great);
	roll_great = get_nb_rolls(*stack_a, great);
	put_nb_on_top(roll_great, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	low = *stack_a;

	low = get_lowest(*stack_a, low);
	roll_low = get_nb_rolls(*stack_a, low);
	put_nb_on_top(roll_low, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	swap_three(stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pa");
	exec_instructions(stack_a, stack_b, "pa");
	exec_instructions(stack_a, stack_b, "ra");

}
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

void	chun11(t_num **stack_a, t_num **stack_b, int ac)
{
}
*/
