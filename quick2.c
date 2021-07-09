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
t_num	*get_nb_middle(t_num *pivot, int min, int max)
{
	int 	j;
	int 	nb_less;
	t_num 	*tmp;
	t_num 	*tmp2;

	tmp = get_nb_by_pos(min, pivot);
	while (tmp->pos < max)
	{
		tmp2 = get_nb_by_pos(min, pivot);
		nb_less = 0;
		while (tmp2->pos < max)
		{
			if (tmp2->val < tmp->val)
				nb_less++;
			tmp2 = tmp2->next;;
		}
		if (nb_less == (max - min) / 2)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_num	*get_pivot(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num	*pivot;

	pivot = *stack_a;
	pivot = get_nb_middle(pivot, min, max);
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
