/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:28:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/26 12:28:30 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repush(t_num **stack_a, t_num **stack_b)
{
	t_num	*highest;
	t_roll	r;

	while (*stack_b)
	{
		highest = get_highest_val(*stack_b);
		r = get_nb_rolls(*stack_b, highest, 'b');
		put_nb_on_top(r, stack_a, stack_b);
		exec_instructions(stack_a, stack_b, "pa");
	}
}

int		is_chunk_in_stack(t_num *stack, int num_chunk)
{
	t_num *cpy;

	cpy = stack;
	while (cpy && cpy->num_chunk != num_chunk)
		cpy = cpy->next;
	if (cpy && cpy->num_chunk == num_chunk)
		return (1);
	return (0);
}

t_num	*assign_chunk(t_num *elet, int nb_sup,
						int nb_chunks, int chunks_size)
{
	int		i;
	int		min_chunk;
	int		max_chunk;

	i = 1;
	if (nb_sup >= 0 && nb_sup < chunks_size)
		elet->num_chunk = 0;
	else
	{
		while (i < nb_chunks)
		{
			min_chunk = chunks_size * i;
			max_chunk = min_chunk + chunks_size;
			if (nb_sup >= min_chunk && nb_sup < max_chunk)
			{
				elet->num_chunk = i;
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
	int 	nb_sup;
	t_num 	*tmp;

	cpy = stack_a;
	while (cpy)
	{
		tmp = stack_a;
		nb_sup = 0;
		while (tmp)
		{
			if (cpy->val > tmp->val)
				nb_sup++;
			tmp = tmp->next;
		}
		cpy = assign_chunk(cpy, nb_sup, nb_chunks, chunks_size);
		cpy = cpy->next;
	}
	return (stack_a);
}
