/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:12:48 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/02 18:58:00 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*get_nb_middle(t_num *pivot, int min, int max)
{
	int 	j;
	int 	nb_less;
	t_num 	*tmp;
	t_num 	*tmp2;


	tmp = go_position(min, pivot);
	while (tmp)
	{
		tmp2 = go_position(min, pivot);
		nb_less = 0;
		while (tmp2)
		{
			if (tmp2->val < tmp->val)
				nb_less++;
			tmp2 = tmp2->next;;
		}
		if (nb_less == (list_length(pivot) - 1) / 2)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_num	*get_pivot(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num	*pivot;

	pivot = *stack_a;
	if (list_length(*stack_a) >= 4)
		pivot = get_nb_middle(pivot, min, max);
	return (pivot);
}

t_num	*go_position(int val, t_num *stack)
{
	t_num	*elet;

	elet = stack;
	if (stack)
	{
		if (val < list_length(stack) / 2)
		{
			while (elet->pos != val)
				elet = elet->next;
		}
		else
		{
			elet = last_num(stack);
			while (elet->pos != val)
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
