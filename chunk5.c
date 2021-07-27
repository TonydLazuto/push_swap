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

t_num 	*scan_stack(t_num **stack_a, int nb_chunks, t_roll *r, int num_chunk)
{
	t_num	*elet_top;
	t_num	*elet_bot;

	elet_top = *stack_a;
	elet_bot = last_num(*stack_a);
	while (elet_top && elet_top->true_pos != num_chunk)
		elet_top = elet_top->next;
	while (elet_bot && elet_bot->true_pos != num_chunk)
		elet_bot = elet_bot->back;
	*r = get_lower_roll(stack_a, elet_top, elet_bot);
	if (ft_strlen(r->ins) == 2)
		return (elet_top);
	return (elet_bot);
}

void	check_roll_stack_b(t_num **stack_a, t_num **stack_b,
					t_roll r_a, int num_chunk)
{
	t_num		*lowest;
	t_roll		r_b;
	const char	*double_roll;

	init_roll(&r_b);
	lowest = NULL;
	double_roll = "rr";
	if (ft_strlen(r_a.ins) == 3)
		double_roll = "rrr";;
	lowest = get_lowest_val(*stack_b);
	r_b = get_nb_rolls(*stack_b, lowest, 'b');
	if (num_chunk == 0)
	{
		while (r_a.pos > 0 && r_b.pos > 0 &&
			ft_strlen(r_a.ins) == ft_strlen(r_b.ins))
		{
			exec_instructions(stack_a, stack_b, double_roll);
			r_a.pos--;
			r_b.pos--;
		}
	}
	put_nb_on_top(r_a, stack_a, stack_b);
}

void	chunk5(t_num **stack_a, t_num **stack_b,
					int chunks_size, int nb_chunks)
{
	t_num*		elet;
	t_roll		r;
	int 		num_chunk;

//printf("_________STACK_A__________________\n");
//print_nb(*stack_a);
	num_chunk = 0;
	init_roll(&r);
	elet = scan_stack(stack_a, nb_chunks, &r, num_chunk);
	put_nb_on_top(r, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

	while (num_chunk < nb_chunks)
	{
	
int i = 0;
		while (is_chunk_in_stack(*stack_a, num_chunk))
		{
	//printf("_______%d___STACK_A__________________\n", i);
	//print_nb(*stack_a);
	//printf("_______%d___STACK_B__________________\n", i);
	//print_nb(*stack_b);
			elet = scan_stack(stack_a, nb_chunks, &r, num_chunk);
	//printf("elet->val : %d\n", elet->val);
	//printf("r.pos : %d\nr.ins : %s\n", r.pos, r.ins);
			check_roll_stack_b(stack_a, stack_b, r, num_chunk);
			exec_instructions(stack_a, stack_b, "pb");
			i++;
		}
		num_chunk++;
	}
	while (*stack_a)
	{
		elet = scan_stack(stack_a, nb_chunks, &r, -1);
		check_roll_stack_b(stack_a, stack_b, r, -1);
		exec_instructions(stack_a, stack_b, "pb");
	}
}

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

void	launch_chunk5(t_num **stack_a, t_num **stack_b)
{
	int nb_chunks;
	int	chunks_size;
	int len;
	
	len = list_length(*stack_a);
	if (len <= 30 && len > 70)
		nb_chunks = 4;
	else if (len <= 70 && len > 150)
		nb_chunks = 5;
	else if (len <= 150 && len > 250)
		nb_chunks = 7;
	else if (len <= 250 && len > 350)
		nb_chunks = 8;
	else
		nb_chunks = 11;

	chunks_size = list_length(*stack_a) / nb_chunks;
	*stack_a = assign_chunks(*stack_a, chunks_size, nb_chunks);
	chunk5(stack_a, stack_b, chunks_size, nb_chunks);
	repush(stack_a, stack_b);
//printf("__________STACK_A__________________\n");
//print_nb(*stack_a);
//printf("__________STACK_B__________________\n");
//print_nb(*stack_b);
}
