/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:30:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/09 17:54:44 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_stack_b(t_num **stack_a, t_num **stack_b, t_num *cpy_pivot, int range)
{	
	int i;

	i = 0;
	while ((*stack_a)->pos != cpy_pivot->pos)
	{
		if ((*stack_a)->val <= cpy_pivot->val)
			exec_instructions(stack_a, stack_b, "pb");
		else
			exec_instructions(stack_a, stack_b, "ra");
		i++;
	}
	exec_instructions(stack_a, stack_b, "pb");
	i++;
	while (i <= range)
	{
		if ((*stack_a)->val < cpy_pivot->val)
			exec_instructions(stack_a, stack_b, "pb");
		else if ((*stack_a)->val > cpy_pivot->val &&
					(*stack_b)->val != cpy_pivot->val)
			exec_instructions(stack_a, stack_b, "rr");
		else
			exec_instructions(stack_a, stack_b, "ra");
		i++;
	}
	//printf("___FILL_______STACK_A__________________\n");
	//print_nb(*stack_a);
	//printf("____FILL______STACK_B__________________\n");
	//print_nb(*stack_b);
}


void		clear_stack_b(t_num **stack_a, t_num **stack_b, t_num *cpy_pivot)
{
	t_roll	roll_b;
	t_num	*elet;

	elet = *stack_b;
	init_roll(&roll_b);
	while (elet->val != cpy_pivot->val)
		elet = elet->next;
	roll_b = get_nb_rolls(*stack_b, elet, 'b');
	put_nb_on_top(roll_b, stack_a, stack_b);
	while (list_length(*stack_b))
		exec_instructions(stack_a, stack_b, "pa");
}

void		resort_sublist(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_roll	r;
	t_num	*lowest;
	t_num	*sub;
	int		pos;

	init_roll(&r);
	sub = get_sub_lst(stack_a, stack_b, min, max);
	pos = get_lowest_pos(sub);
	lowest = get_nb_by_pos(pos, *stack_a);
	clear_lst(&sub);

	r = get_nb_rolls(*stack_a, lowest, 'a');
	put_nb_on_top(r, stack_a, stack_b);
}

t_num		*partition(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num*		pivot;
	t_num*		cpy_pivot;
	t_num*		cur_min;
	t_roll		roll_a;

	pivot = get_pivot(stack_a, stack_b, min, max);
//printf("pivot->pos : %d\npivot->val : %d\n", pivot->pos, pivot->val);
	cpy_pivot = new_nb(pivot->val, pivot->pos, pivot->true_pos);
	if (!cpy_pivot)
		ft_error(stack_a, stack_b);
	cur_min = get_nb_by_pos(min, *stack_a);
	roll_a = get_nb_rolls(*stack_a, cur_min, 'a');
	put_nb_on_top(roll_a, stack_a, stack_b);

//printf("______CUR_MIN____STACK_A__________________\n");
//print_nb(*stack_a);
	fill_stack_b(stack_a, stack_b, cpy_pivot, max - min);
	resort_sublist(stack_a, stack_b, min, max);
//printf("___SUB___RESORT____STACK_A__________________\n");
//print_nb(*stack_a);
	clear_stack_b(stack_a, stack_b, cpy_pivot);
//printf("___CLEAR___________STACKS___________________\n");
//print_nb(*stack_a);

	return (cpy_pivot);
}

int			quick_sort(t_num **stack_a, t_num **stack_b, int min, int max)
{
	int			pos;
	static int	last_min_val = 0;
	t_num*		pivot;
	t_num*		cpy_pivot;

	set_num_pos(stack_a);
	pivot = NULL;
	if (min <= max)
	{
//printf("%d : min\n%d : max\n", min, max);
		if (min == max)
			pos = get_pos_single_range(stack_a, min);
		else
		{
			cpy_pivot = partition(stack_a, stack_b, min ,max);
			resort_multiple_range(stack_a, stack_b, last_min_val, min);
			pos = get_pos_multiple_range(stack_a, cpy_pivot);
			clear_lst(&cpy_pivot);
		}
		last_min_val = (*stack_a)->val;
/*
printf("_______STACK_A__END________\n");
print_nb(*stack_a);
printf("___________________----------------------------____________________\n");
printf("___________________----------------------------____________________\n");
printf("___________________----------------------------____________________\n");
*/
		quick_sort(stack_a, stack_b, min, pos - 1);
		quick_sort(stack_a, stack_b, pos + 1, max);
	}
	return (pos);
}
