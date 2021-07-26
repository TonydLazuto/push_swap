/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:11:38 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/26 12:11:39 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_chunk(t_num **stack_a, t_num **stack_b, t_num *chunk)
{
	t_num		*lowest_chunk;
	t_num		*lowest_a;
	t_roll		r[2];

	while (chunk)
	{
		lowest_chunk = get_lowest_val(chunk);
		lowest_a = get_nb_by_val(lowest_chunk->val, *stack_a);
printf("lowest_chunk->val : %d\n", lowest_chunk->val);
		r[0] = get_nb_rolls(*stack_a, lowest_a, 'a');
		r[1] = get_nb_rolls(chunk, lowest_chunk, 'a');
		put_nb_on_top(r[0], stack_a, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
printf("___CHUNK_IN__________________________\n");
print_nb(chunk);
		chunk = pop_elet(chunk, lowest_chunk, r[1]);
printf("___CHUNK_OUT__________________________\n");
print_nb(chunk);
printf("___IN_______STACK_A__________________\n");
print_nb(*stack_a);
		resort3(stack_a, stack_b);
printf("_____RESORT____STACK_A__________________\n");
print_nb(*stack_a);
	}
printf("___FILL_______STACK_A__________________\n");
print_nb(*stack_a);
printf("____FILL______STACK_B__________________\n");
print_nb(*stack_b);
}

void		push5chunk(t_num **stack_a, t_num **stack_b)
{
	int 	chunk_size;
	t_num	*chunk;
	int		i;

	i = 0;
	
	chunk_size = (list_length(*stack_a) / 5) + 1;
	chunk = get_chunk(stack_a, chunk_size);
	//while (*stack_a)
	//{
		push_chunk(stack_a, stack_b, chunk);
		i++;
	//}
}

void		chunk4(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num*		pivot;
	
	push5chunk(stack_a, stack_b);
}

void	launch_chunk4(t_num **stack_a, t_num **stack_b)
{
	int min;
	int max;
	int pos;

	min = 0;
	max = list_length(*stack_a) - 1;
	set_num_pos(stack_a);
	chunk4(stack_a, stack_b, min, max);
}