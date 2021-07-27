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

t_num 	*scan_stack(t_num **stack_a, int nb_chunks, t_roll *r)
{
	t_num	*elet_top;
	t_num	*elet_bot;

	elet_top = *stack_a;
	elet_bot = last_num(*stack_a);
	while (elet_top && elet_top->true_pos != 0)
		elet_top = elet_top->next;
	while (elet_bot && elet_bot->true_pos != 0)
		elet_bot = elet_bot->back;
	*r = get_lower_roll(stack_a, elet_top, elet_bot);
	if (ft_strlen(r->ins) == 2)
		return (elet_top);
	return (elet_bot);
}

void	check_roll_stack_b(t_num **stack_a, t_num **stack_b,
					t_num *elet, t_roll r_a)
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
	if (ft_strlen(r_a.ins) == ft_strlen(r_b.ins))
	{
		while (r_a.pos > 0 && r_b.pos > 0)
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
	int			pos;
	t_roll		r;

printf("_________STACK_A__________________\n");
print_nb(*stack_a);
	init_roll(&r);
	elet = scan_stack(stack_a, nb_chunks, &r);
	put_nb_on_top(r, stack_a, stack_b);
	exec_instructions(stack_a, stack_b, "pb");

int i = 0;

	while (is_chunk_in_stack(*stack_a, 0))
	{
printf("_______%d___STACK_A__________________\n", i);
print_nb(*stack_a);
printf("_______%d___STACK_B__________________\n", i);
print_nb(*stack_b);
		elet = scan_stack(stack_a, nb_chunks, &r);
printf("elet->val : %d\n", elet->val);
printf("r.pos : %d\nr.ins : %s\n", r.pos, r.ins);
		check_roll_stack_b(stack_a, stack_b, elet, r);
		exec_instructions(stack_a, stack_b, "pb");
		i++;
	}
}


void	launch_chunk5(t_num **stack_a, t_num **stack_b)
{
	int nb_chunks = 5; // en fonction 100 200 300...
	int	chunks_size;

	chunks_size = list_length(*stack_a) / nb_chunks;
	set_num_pos(stack_a);
	*stack_a = assign_chunks(*stack_a, chunks_size, nb_chunks);
	chunk5(stack_a, stack_b, chunks_size, nb_chunks);
printf("__________STACK_A__________________\n");
print_nb(*stack_a);
printf("__________STACK_B__________________\n");
print_nb(*stack_b);
printf("___-----------------------------------______________________________\n");
printf("___-----------------------------------______________________________\n");
printf("___-----------------------------------______________________________\n");
}
