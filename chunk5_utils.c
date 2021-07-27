/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk5_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:28:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/26 12:28:30 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_chunk_in_stack(t_num *stack, int num_chunk)
{
	t_num *cpy;

	cpy = stack;
	while (cpy && cpy->true_pos != num_chunk)
		cpy = cpy->next;
	if (cpy && cpy->true_pos == num_chunk)
		return (1);
	return (0);
}

t_roll	get_lower_roll(t_num **stack_a,
			t_num *elet_top, t_num *elet_bot)
{
	t_roll	r[2];

	init_roll(&r[0]);
	init_roll(&r[1]);
	r[0] = get_nb_rolls(*stack_a, elet_top, 'a');
	r[1] = get_nb_rolls(*stack_a, elet_bot, 'a');
	if (r[0].pos < r[1].pos)
		return (r[0]);
	return (r[1]);
}

t_num	*assign_chunk(t_num *elet, int nb_less,
						int nb_chunks, int chunks_size)
{
	int		i;
	int		min_chunk;
	int		max_chunk;

	i = 1;
	if (nb_less >= 0 && nb_less < chunks_size)
		elet->true_pos = 0;
	else
	{
		while (i < nb_chunks)
		{
			min_chunk = chunks_size * i;
			max_chunk = chunks_size * i + chunks_size;
			if (nb_less >= min_chunk && nb_less < max_chunk)
			{
				elet->true_pos = i;
				break ;
			}
			i++;
		}
	}
	return (elet);
}

t_num	*assign_chunks(t_num *stack_a, int chunks_size,
				int nb_chunks)
{
	t_num	*cpy;
	int 	j;
	int 	nb_less;
	t_num 	*tmp;

	cpy = stack_a;
	while (cpy)
	{
		tmp = stack_a;
		nb_less = 0;
		while (tmp)
		{
			if (cpy->val > tmp->val)
				nb_less++;
			tmp = tmp->next;
		}
		cpy = assign_chunk(cpy, nb_less, nb_chunks, chunks_size);
		cpy = cpy->next;
	}
	return (stack_a);
}

/*
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
*/