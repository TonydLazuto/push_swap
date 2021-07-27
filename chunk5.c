/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:11:38 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/26 12:11:39 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void		push_chunk(t_num **stack_a, t_num **stack_b, t_num *chunk)
{
	t_num		*lowest_chunk;
	t_num		*lowest_a;
	t_roll		r[2];

	init_roll(&r[0]);
	init_roll(&r[0]);
	while (chunk)
	{
		lowest_chunk = get_lowest_val(chunk);
		lowest_a = get_nb_by_val(lowest_chunk->val, *stack_a);
//printf("lowest_chunk->val : %d\n", lowest_chunk->val);
		r[0] = get_nb_rolls(*stack_a, lowest_a, 'a');
		r[1] = get_nb_rolls(chunk, lowest_chunk, 'a');
		put_nb_on_top(r[0], stack_a, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
//printf("___CHUNK_IN__________________________\n");
//print_nb(chunk);
		chunk = pop_elet(chunk, lowest_chunk, r[1]);
//printf("___CHUNK_OUT__________________________\n");
//print_nb(chunk);
//printf("___IN_______STACK_A__________________\n");
//print_nb(*stack_a);
		if (*stack_a)
			resort3(stack_a, stack_b);
//printf("_____RESORT____STACK_A__________________\n");
//print_nb(*stack_a);
	}
//printf("___FILL_______STACK_A__________________\n");
//print_nb(*stack_a);
//printf("____FILL______STACK_B__________________\n");
//print_nb(*stack_b);
}

void		push5chunk(t_num **stack_a, t_num **stack_b)
{
	int 	chunk_size;
	t_num	*chunk;
	int		i;

	i = 0;
	chunk = NULL;
	chunk_size = (list_length(*stack_a) / 5) + 1;
	while (*stack_a)
	{
		if (list_length(*stack_a) < chunk_size)
			chunk_size = list_length(*stack_a);
		//printf("chunk_size : %d\n", chunk_size);
		chunk = get_chunk(stack_a, chunk_size);
		push_chunk(stack_a, stack_b, chunk);
printf("___CHUNK_______STACK_A__________________\n");
print_nb(*stack_a);
printf("____CHUNK______STACK_B__________________\n");
print_nb(*stack_b);
		i++;
	}
}

void		chunk5(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num*		pivot;
	
	push5chunk(stack_a, stack_b);
}
*/

void	launch_chunk5(t_num **stack_a, t_num **stack_b)
{
	int min;
	int max;
	int pos;
	int nb_chunks = 5; // en fonction 100 200 300...

	min = 0;
	max = list_length(*stack_a) - 1;
	set_num_pos(stack_a);
	assign_chunks(stack_a, nb_chunks);
printf("___CHUNK_______STACK_A__________________\n");
print_nb(*stack_a);
//printf("elet->val : %d\nnb_less : %d\n", cpy->val, nb_less);
printf("___-----------------------------------______________________________\n");
printf("___-----------------------------------______________________________\n");
printf("___-----------------------------------______________________________\n");
	//chunk5(stack_a, stack_b, min, max);
}
