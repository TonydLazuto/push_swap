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

void		resort(t_num **stack_a, t_num **stack_b, int last_min_val)
{
	t_num	*lowest;
	t_roll	r;

	lowest = NULL;
	init_roll(&r);

printf("______STACK_A_______BE4_RESORT_______\n");
print_nb(*stack_a);

	lowest = get_nb_by_val(last_min_val, *stack_a);
	r = get_nb_rolls(*stack_a, lowest, 'a');
	put_nb_on_top(r, stack_a, stack_b);
	set_num_pos(stack_a);
}

int			check_end(t_num **stack_a)
{
	t_num	*elet;

	elet = *stack_a;
	while (elet)
	{
		if (elet->true_pos == -1)
			return (0);
		elet = elet->next;
	}
	return (1);
}