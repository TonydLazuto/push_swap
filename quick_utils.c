/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:12:48 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/09 15:52:46 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 * Here, I will find the pivot which is
 * the middle value in the stack.
 * Thereby, the precision of the quicksort algorithm
 * will be more like O=nlog(n) than O=(n square).
 *
 * get_nb_middle() find the best pivot
 * which is the same amount of < than > with
 * all elements between min & max
 **/

t_num	*get_pivot(t_num *stack_a, int min, int max)
{
	t_num	*pivot;
	t_num	*cpy;
	int 	j;
	int 	nb_less;
	t_num 	*tmp;

	cpy = stack_a;
	cpy = get_nb_by_pos(min, stack_a);
	while (cpy->pos < max)
	{
		tmp = get_nb_by_pos(min, stack_a);
		nb_less = 0;
		while (tmp && tmp->pos <= max)
		{
			if (tmp->val < cpy->val)
				nb_less++;
			tmp = tmp->next;
		}
		if (nb_less == (max - min) / 2)
			break ;
		cpy = cpy->next;
	}
	pivot = new_nb(cpy->val, cpy->pos, cpy->true_pos);
	return (pivot);
}

t_num	*get_nb_by_val(int val, t_num *stack)
{
	t_num	*elet;

	elet = stack;
	while (elet->val != val)
		elet = elet->next;
	return (elet);
}

t_num	*get_nb_by_pos(int pos, t_num *stack)
{
	t_num	*elet;

	elet = stack;
	if (stack)
	{
		if (pos < list_length(stack) / 2)
		{
			while (elet->pos != pos)
				elet = elet->next;
		}
		else
		{
			elet = last_num(stack);
			while (elet->pos != pos)
				elet = elet->back;
		}
	}
	return (elet);
}

void	set_num_pos(t_num **stack)
{
	t_num	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	if (*stack)
	{
		while (tmp)
		{
			tmp->pos = i;
			tmp = tmp->next;
			i++;
		}
	}
}

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