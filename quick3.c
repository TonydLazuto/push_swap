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
	t_num	*cpy;

	cpy = *stack_a;
	sub_lst = NULL;
	while (cpy)
	{
		if (cpy->pos >= min && cpy->pos <= max)
			sub_lst = push_back(sub_lst, cpy->val,
				cpy->pos, cpy->true_pos);
		cpy = cpy->next;
	}
	return (sub_lst);
}

