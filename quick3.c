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

void		resort2(t_num **stack_a, t_num **stack_b, int last_min_pos)
{
	t_num	*lowest;
	t_roll	r;

	lowest = NULL;
	init_roll(&r);

	lowest = get_nb_by_pos(last_min_pos, *stack_a);
	r = get_nb_rolls(*stack_a, lowest, 'a');
	put_nb_on_top(r, stack_a, stack_b);
	set_num_pos(stack_a);
}

void		resort(t_num **stack_a, t_num **stack_b,
				 int last_min_pos, int min)
{
	if (min == 0)
		set_num_pos(stack_a);
	else
		resort2(stack_a, stack_b, last_min_pos);
}

int			get_pos_multiple_range(t_num **stack_a, t_num *pivot)
{
	t_num*	cpy;

	cpy = *stack_a;
	cpy = get_nb_by_val(pivot->val, *stack_a);
	cpy->true_pos = cpy->pos;
	return (cpy->true_pos);	
}