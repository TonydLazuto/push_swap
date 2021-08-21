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
int		scan_stack_b(t_num **stack_b, t_roll r_a)
{
	int		actions;
	int		is_switch;
	t_num	*elet_b;
	int		first_val;

	actions = 0;
	is_switch = 0;
	elet_b = *stack_b;
	first_val = (*stack_b)->val;
	if (ft_strlen(r_a.ins) == 2)
	{
		while(actions < r_a.pos && elet_b && elet_b->next)
		{
			if (elet_b->val < elet_b->next->val)
				is_switch++;
			elet_b->next;
			actions++;
		}
	}
	else
	return (actions);
}
*/
t_roll	scan_stack_a(t_num **stack_a, int num_chunk)
{
	t_num	*elet_top;
	t_num	*elet_bot;
	t_roll	r;

	elet_top = *stack_a;
	elet_bot = last_num(*stack_a);
	while (elet_top && elet_top->num_chunk != num_chunk)
		elet_top = elet_top->next;
	while (elet_bot && elet_bot->num_chunk != num_chunk)
		elet_bot = elet_bot->back;
	r = get_the_lowest_dist(stack_a, elet_top, elet_bot);
	return (r);
}

void	chunk5(t_num **stack_a, t_num **stack_b, int nb_chunks)
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
	//printf("_______%d___STACK_A__________________\n", i);
	//print_nb(*stack_a);
	//printf("_______%d___STACK_B__________________\n", i);
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

void	launch_chunk5(t_num **stack_a, t_num **stack_b, int ac)
{
	int nb_chunks;
	int	chunks_size;

	if (ac <= 30 && ac > 70)
		nb_chunks = 4;
	else if (ac <= 70 && ac > 150)
		nb_chunks = 5;
	else if (ac <= 150 && ac > 250)
		nb_chunks = 7;
	else if (ac <= 250 && ac > 350)
		nb_chunks = 8;
	else
		nb_chunks = 11;
	chunks_size = list_length(*stack_a) / nb_chunks;
	*stack_a = assign_chunks(*stack_a, chunks_size, nb_chunks);
	chunk5(stack_a, stack_b, nb_chunks);
	repush(stack_a, stack_b);
printf("__________STACK_A__________________\n");
print_nb(*stack_a);
printf("__________STACK_B__________________\n");
print_nb(*stack_b);

}
