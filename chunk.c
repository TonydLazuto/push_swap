/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:11:38 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/26 12:11:39 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_roll	scan_stack_a(t_num **stack_a, int num_chunk)
{
	t_num	*elet_top;
	t_num	*elet_bot;
	t_roll	r[2];

	elet_top = *stack_a;
	elet_bot = last_num(*stack_a);
	while (elet_top && elet_top->num_chunk != num_chunk)
		elet_top = elet_top->next;
	while (elet_bot && elet_bot->num_chunk != num_chunk)
		elet_bot = elet_bot->back;
	r[0] = get_nb_rolls(*stack_a, elet_top, 'a');
	r[1] = get_nb_rolls(*stack_a, elet_bot, 'a');
	if (r[0].pos < r[1].pos)
		return (r[0]);
	return (r[1]);
}

void	chunk(t_num **stack_a, t_num **stack_b, int nb_chunks)
{
	t_num*		elet;
	t_roll		r;
	int 		num_chunk;

//printf("_________STACK_A__________________\n");
//print_nb(*stack_a);
	num_chunk = 0;
	while (*stack_a)
	{
		if (num_chunk == nb_chunks)
			num_chunk = -1;
		while (is_chunk_in_stack(*stack_a, num_chunk))
		{
	//printf("_______%d___STACK_A__________________\n", num_chunk);
	//print_nb(*stack_a);
	//printf("_______%d___STACK_B__________________\n", num_chunk);
	//print_nb(*stack_b);
			r = scan_stack_a(stack_a, num_chunk);
	//printf("elet->val : %d\n", elet->val);
	//printf("r.pos : %d\nr.ins : %s\n", r.pos, r.ins);
			put_nb_on_top(r, stack_a, stack_b);
			exec_instructions(stack_a, stack_b, "pb");
		}
		num_chunk++;
	}
}

void	launch_chunk(t_num **stack_a, t_num **stack_b, int ac)
{
	int nb_chunks;
	int	chunks_size;

	if (ac >= 30 && ac < 70)
		nb_chunks = 3;
	else if (ac >= 70 && ac < 150)
		nb_chunks = 5;
	else if (ac >= 150 && ac < 250)
		nb_chunks = 7;
	else if (ac >= 250 && ac < 350)
		nb_chunks = 8;
	else
		nb_chunks = 11;
	chunks_size = list_length(*stack_a) / nb_chunks;
	*stack_a = assign_chunks(*stack_a, chunks_size, nb_chunks);
	chunk(stack_a, stack_b, nb_chunks);
	repush(stack_a, stack_b);
/*
printf("__________STACK_A__________________\n");
print_nb(*stack_a);
printf("__________STACK_B__________________\n");
print_nb(*stack_b);
*/
}
