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

void		fill_stack_b(t_num **stack_a, t_num **stack_b, t_num *pivot, int max)
{	
	while ((*stack_a)->pos < pivot->pos)
	{
printf("(*stack_a)->pos: %d\n", (*stack_a)->pos);
		if ((*stack_a)->val < pivot->val)
			exec_instructions(stack_a, stack_b, "pb");
		else
			exec_instructions(stack_a, stack_b, "ra");
	}
	exec_instructions(stack_a, stack_b, "pb");
	while ((*stack_a)->pos != max)
	{
		if ((*stack_a)->val < pivot->val)
			exec_instructions(stack_a, stack_b, "pb");
		else if ((*stack_a)->val > pivot->val &&
					(*stack_b)->val != pivot->val)
			exec_instructions(stack_a, stack_b, "rr");
		else
			exec_instructions(stack_a, stack_b, "ra");
	}
	printf("___FILL_______STACK_A__________________\n");
	print_nb(*stack_a);
	printf("____FILL______STACK_B__________________\n");
	print_nb(*stack_b);
}


void		clear_stack_b(t_num **stack_a, t_num **stack_b, t_num *cpy_pivot)
{
	t_roll	roll_b;
	t_num	*new_piv;

	new_piv = *stack_b;
	init_roll(&roll_b);
	set_num_pos(stack_b);
	while (new_piv->val != cpy_pivot->val)
		new_piv = new_piv->next;
	roll_b = get_nb_rolls(*stack_b, new_piv, 'b');
	put_nb_on_top(roll_b, stack_a, stack_b);
	while (list_length(*stack_b))
		exec_instructions(stack_a, stack_b, "pa");
}

void		resort_sublist(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_roll	r;
	t_num	*lowest;
	int		*sub;
	int		pos;

	sub = get_sub_lst2(stack_a, stack_b, min, max);
	pos = get_lowest_pos2(sub, min, max);
	lowest = get_nb_by_pos(pos, *stack_a);

	printf("_____________LOWEST__________________\n");
	print_nb(lowest);


printf("lowest->val : %d\n", lowest->val);
printf("lowest->pos : %d\n", lowest->pos);
	init_roll(&r);

	r = get_nb_rolls(*stack_a, lowest, 'a');
	put_nb_on_top(r, stack_a, stack_b);
	free(sub);
	sub = NULL;
}

int			partition(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num*	pivot;
	t_num*	cpy_pivot;
	t_num*	cur_min;
	t_roll	roll_a;

	//print_nb(*stack_a);
printf("____________________________\n");
	pivot = get_pivot(stack_a, stack_b, min, max);
printf("pivot->val : %d\n", pivot->val);
printf("____________________________\n");

	cur_min = get_nb_by_pos(min, *stack_a);
	roll_a = get_nb_rolls(*stack_a, cur_min, 'a');
	put_nb_on_top(roll_a, stack_a, stack_b);

//printf("______CUR_MIN____STACK_A__________________\n");
//print_nb(*stack_a);
	cpy_pivot = new_nb(pivot->val, pivot->pos, pivot->true_pos);
	if (!cpy_pivot)
		ft_error(stack_a, stack_b);

	fill_stack_b(stack_a, stack_b, cpy_pivot, max);
	resort_sublist(stack_a, stack_b, min, max);
printf("______RESORT____STACK_A__________________\n");
print_nb(*stack_a);
	clear_stack_b(stack_a, stack_b, cpy_pivot);
printf("______AFTER CLEAR B____STACK_A__________________\n");
print_nb(*stack_a);

	set_num_pos(stack_a);
	pivot = get_nb_by_val(cpy_pivot->val, *stack_a);
	pivot->true_pos = pivot->pos;
	return (pivot->pos);
}

int			quick_sort(t_num **stack_a, t_num **stack_b, int min, int max)
{
	int		pos;

	set_num_pos(stack_a);
	if (min < max)
	{
printf("__________STACK_A__________________\n");
print_nb(*stack_a);
		pos = partition(stack_a, stack_b, min ,max);
	/*
printf("__________STACK_A__________________\n");
print_nb(*stack_a);
printf("__________STACK_B__________________\n");
print_nb(*stack_b);
		quick_sort(stack_a, stack_b, min, pos);
		quick_sort(stack_a, stack_b, pos + 1, max);
		*/
	}
	return (pos);
}

void		myquick(t_num **stack_a, t_num **stack_b)
{
	int min;
	int max;
	int pos;
	
	min = 0;
	max = list_length(*stack_a) - 1;
	pos = quick_sort(stack_a, stack_b, min, max);
/*		quick_sort(stack_a, stack_b, min, pos);
		printf("__________STACK_A__________________\n");
		print_nb(*stack_a);
*/		
	printf("%d : pos\n%d : max\n", pos, max);
		quick_sort(stack_a, stack_b, pos + 1, max);
		printf("__________STACK_A__________________\n");
		print_nb(*stack_a);

}

