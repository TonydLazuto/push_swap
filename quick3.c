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

t_num	*get_sub_lst(t_num **stack_a,
 int min, int max)
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

void		resort2(t_num **stack_a, t_num **stack_b, int last_min_val)
{
	t_num	*lowest;
	t_roll	r;

	lowest = NULL;
	init_roll(&r);

	lowest = get_nb_by_val(last_min_val, *stack_a);
	r = get_nb_rolls(*stack_a, lowest, 'a');
	put_nb_on_top(r, stack_a, stack_b);
	set_num_pos(stack_a);
}

void		resort(t_num **stack_a, t_num **stack_b,
				 int last_min_val, int min)
{
	if (min == 0)
		set_num_pos(stack_a);
	else
		resort2(stack_a, stack_b, last_min_val);
}

int			get_pos_multiple_range(t_num **stack_a, t_num *cpy_pivot)
{
	t_num*	pivot;

	pivot = *stack_a;
	pivot = get_nb_by_val(cpy_pivot->val, *stack_a);
	pivot->true_pos = pivot->pos;
	return (pivot->true_pos);	
}