/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk4_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:28:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/26 12:28:30 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*get_chunk(t_num **stack_a, int chunk_size)
{
	t_num	*sub_lst;
	t_num	*cpy;
	int		i;

	i = 0;
	cpy = *stack_a;
	sub_lst = NULL;
	while (cpy && i < chunk_size)
	{
		sub_lst = push_back(sub_lst, cpy->val,
			cpy->pos, cpy->true_pos);
		cpy = cpy->next;
		i++;
	}
	return (sub_lst);
}

void		resort3(t_num **stack_a, t_num **stack_b)
{
	int		low;
	t_num	*lowest;
	t_roll	r;

	init_roll(&r);
	low = get_lowest_pos(*stack_a);
	lowest = get_nb_by_pos(low, *stack_a);
	r = get_nb_rolls(*stack_a, lowest, 'a');
	put_nb_on_top(r, stack_a, stack_b);
	set_num_pos(stack_a);
}

t_num		*roll_chunk(t_num *cur)
{	
	if (cur && cur->next)
	{
		cur = push_back(cur, cur->val, cur->pos, cur->true_pos);
		if (!cur)
			return (NULL);
		cur = pop_front(cur);
	}
	return (cur);
}

t_num		*reverse_roll_chunk(t_num *cur)
{
	if (cur && cur->next)
	{
		cur = push_front(cur, last_num(cur)->val,
				last_num(cur)->pos, last_num(cur)->true_pos);
		if (!cur)
			return (NULL);
		cur = pop_back(cur);
	}
	return (cur);
}

t_num	*pop_elet(t_num *chunk, t_num *lowest, t_roll r)
{
	if (ft_strlen(r.ins) == 2)
	{
		while (r.pos != 0)
		{
			chunk = roll_chunk(chunk);
			r.pos--;
		}
	}
	else
	{
		while (r.pos != 0)
		{
			chunk = reverse_roll_chunk(chunk);
			r.pos--;
		}
	}
	chunk = pop_front(chunk);
	return (chunk);
}