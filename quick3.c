/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 08:29:26 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/09 17:51:58 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lowest_pos(t_num *stack_a)
{
	int		valid;
	t_num	*tmp;
	t_num	*elet;
	int		size;

	tmp = NULL;
	elet = stack_a;
	size = list_length(stack_a);
	while (elet)
	{
		tmp = stack_a;
		valid = 1;
		while (tmp)
		{
			if (elet->pos < tmp->pos)
				valid++;
			tmp = tmp->next;
		}
		if (valid == size)
			return (elet->pos);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet->pos);
}

t_num	*get_sub_lst(t_num **stack_a,
			t_num **stack_b, int min, int max)
{
	t_num	*sub_lst;
	t_num	*new_stack;

	sub_lst = *stack_a;
	new_stack = NULL;
	if (min == 0 && max == (list_length(*stack_a) + list_length(*stack_b) - 1))
		return (*stack_a);
	while (sub_lst->pos != min)
		sub_lst = sub_lst->next;
	printf("new stack len %d\n", list_length(new_stack));
	new_stack = new_nb(sub_lst->val, sub_lst->pos, sub_lst->true_pos);
	if (!new_stack)
		ft_error(stack_a, stack_b);
	sub_lst = *stack_a;
	while (sub_lst->pos != max)
	{
		new_stack = push_back(new_stack, sub_lst->val,
				sub_lst->pos, sub_lst->true_pos);
		if (!new_stack)
			ft_error(stack_a, stack_b);
		sub_lst = sub_lst->next;
	}
	return (new_stack);
}

int		*get_sub_lst2(t_num **stack_a,
			t_num **stack_b, int min, int max)
{
	t_num	*cpy;
	int		*stack;
	int		i;

	cpy = *stack_a;
	i = 0;
	stack = malloc(sizeof(int) * (max - min)); // + ou - 1
	if (!stack)
		ft_error(stack_a, stack_b);
	while (cpy->pos != min)
		cpy = cpy->next;
	while (cpy && cpy->pos != max)
	{
		stack[i++] = cpy->val;
		cpy = cpy->next;
	}
	if (cpy->pos != max)
	{
		cpy = *stack_a;
		while (cpy->pos != max)
		{
			stack[i++] = cpy->val;
			cpy = cpy->next;
		}
	}
	return (stack);
}

int		get_lowest_pos2(int *sub_stack, int min, int max)
{
	int		valid;
	int		i;
	int		j;
	int		size;

	size = max - min;
	i = 0;
	while (sub_stack[i])
	{
		j = 0;
		valid = 1;
		while (sub_stack[j])
		{
			if (sub_stack[i] < sub_stack[j])
				valid++;
			j++;
		}
		if (valid == size)
			return (i);
		i++;
	}
	return (i);
}
