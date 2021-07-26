/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myquick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:30:29 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/24 18:16:44 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sub = get_sub_lst(stack_a, min, max);
	pos = get_lowest_pos(sub);
	lowest = get_nb_by_pos(pos, *stack_a);
	clear_lst(&sub);

	r = get_nb_rolls(*stack_a, lowest, 'a');
	put_nb_on_top(r, stack_a, stack_b);
}

/**
 * use the tmp_pivot only if the distance
 * from *stack_a to cur_min greater than 5;
 * */

void		go_to_min(t_num **stack_a, t_num **stack_b, int min)
{
	t_num*		cur_min;
	t_num*		sub;
	t_num		*tmp_pivot;
	t_roll		r;

	init_roll(&r);
	tmp_pivot = NULL;
	cur_min = get_nb_by_pos(min, *stack_a);
	r = get_nb_rolls(*stack_a, cur_min, 'a');
//printf("-->r.pos = %d\n-->r.ins = %s\n\n", r.pos, r.ins);

	sub = get_sub_tmp_pivot(stack_a, r);
	if (sub && list_length(sub) > 5)
	{
//printf("______GET_SUB_TMP--------------/////////////////////------------------\n");
//print_nb(sub);
		tmp_pivot = get_pivot(sub, 0, list_length(sub) - 1);
		if (!tmp_pivot)
		ft_error(stack_a, stack_b);
//printf("\ntmp_pivot->val : %d\n", tmp_pivot->val);
		clear_lst(&sub);
	}
	if (r.pos > 2)
		go_to_min2(stack_a, stack_b, r, tmp_pivot);
	else
		put_nb_on_top(r, stack_a, stack_b);
//printf("-->r.pos = %d\n-->r.ins = %s\n\n", r.pos, r.ins);
}

t_num		*partition(t_num **stack_a, t_num **stack_b, int min, int max)
{
	t_num*		pivot;

	pivot = get_pivot(*stack_a, min, max);
	if (!pivot)
		ft_error(stack_a, stack_b);
printf("pivot->pos : %d\npivot->val : %d\n", pivot->pos, pivot->val);
	go_to_min(stack_a, stack_b, min);
printf("______CUR_MIN____STACK_A__________________\n");
print_nb(*stack_a);
	//check_fill_direction(stack_a, pivot, max - min);
	fill_stack_b(stack_a, stack_b, pivot, max - min);
	//fill_and_sort(stack_a, stack_b, pivot, max - min);
	//clear_lst(&sub);
printf("___FILL_______STACK_A__________________\n");
print_nb(*stack_a);
printf("____FILL______STACK_B__________________\n");
print_nb(*stack_b);
	resort_sublist(stack_a, stack_b, min, max);
printf("___SUB___RESORT____STACK_A__________________\n");
print_nb(*stack_a);
	clear_stack_b(stack_a, stack_b, pivot);
printf("___CLEAR___________STACKS___________________\n");
print_nb(*stack_a);

	return (pivot);
}

int			quick_sort(t_num **stack_a, t_num **stack_b, int min, int max)
{
	int			pos;
	static int	last_min_pos = 0;
	t_num*		pivot;

	set_num_pos(stack_a);
printf("%d : min\n%d : max\n", min, max);
	pivot = partition(stack_a, stack_b, min ,max);

	resort(stack_a, stack_b, last_min_pos, min);

print_nb(*stack_a);
	pos = get_pos_multiple_range(stack_a, pivot);
	clear_lst(&pivot);
printf("___END___________STACK_A___________________\n");
print_nb(*stack_a);
printf("___-----------------------------------______________________________\n");
printf("___-----------------------------------______________________________\n");
printf("___-----------------------------------______________________________\n");
	last_min_pos = (*stack_a)->pos;
	return (pos);
}
