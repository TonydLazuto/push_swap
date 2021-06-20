/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:31:49 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/19 10:10:51 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		go_switch(t_num **stack_a, t_num **stack_b,
							const char *ins)
{
	if (!ft_strncmp(ins, "sa", 2))
		*stack_a = switch_nb(*stack_a, *stack_b, ins);
	if (!ft_strncmp(ins, "sb", 2))
		*stack_b = switch_nb(*stack_b, *stack_a, ins);
	if(!ft_strncmp(ins, "ss", 2))
	{
		*stack_a = switch_nb(*stack_a, *stack_b, ins);
		*stack_b = switch_nb(*stack_b, *stack_a, "");
	}
}

static void		go_push(t_num **stack_a, t_num **stack_b,
							const char *ins)
{
	if (!ft_strncmp(ins, "pa", 2))
		push_nb(stack_a, stack_b, ins);
	if (!ft_strncmp(ins, "pb", 2))
		push_nb(stack_b, stack_a, ins);
}

static void		go_roll(t_num **stack_a, t_num **stack_b,
							const char *ins)
{
	if (ft_strlen(ins) == 2)
	{
		if (!ft_strncmp(ins, "ra", 2))
			*stack_a = roll_stack(*stack_a, *stack_b, ins);
		if (!ft_strncmp(ins, "rb", 2))
			*stack_b = roll_stack(*stack_b, *stack_a, ins);
		if (!ft_strncmp(ins, "rr", 2))
		{
			*stack_a = roll_stack(*stack_a, *stack_b, ins);
			*stack_b = roll_stack(*stack_b, *stack_a, "");
		}
	}
}

static void		go_reverse_roll(t_num **stack_a, t_num **stack_b,
								 	const char *ins)
{
	if (!ft_strncmp(ins, "rra", 3))
		*stack_a = reverse_roll_stack(*stack_a, *stack_b, ins);
	if (!ft_strncmp(ins, "rrb", 3))
		*stack_b = reverse_roll_stack(*stack_b, *stack_a, ins);
	if (!ft_strncmp(ins, "rrr", 3))
	{
		*stack_a = reverse_roll_stack(*stack_a, *stack_b, ins);
		*stack_b = reverse_roll_stack(*stack_b, *stack_a, "");
	}
}

void			exec_instructions(t_num **stack_a, t_num **stack_b,
								const char *ins)
{
	if (!ft_strncmp(ins, "sa", 2) || !ft_strncmp(ins, "sb", 2) || !ft_strncmp(ins, "ss", 2))
		go_switch(stack_a, stack_b, ins);
	if (!ft_strncmp(ins, "pa", 2) || !ft_strncmp(ins, "pb", 2))
		go_push(stack_a, stack_b, ins);
	if (!ft_strncmp(ins, "ra", 2) || !ft_strncmp(ins, "rb", 2) || !ft_strncmp(ins, "rr", 2))
		go_roll(stack_a, stack_b, ins);
	if (!ft_strncmp(ins, "rra", 3) || !ft_strncmp(ins, "rrb", 3)
			|| !ft_strncmp(ins, "rrr", 3))
		go_reverse_roll(stack_a, stack_b, ins);
	
	printf("|--%s--|\nStack A :\n", ins);
	print_nb(*stack_a);
	printf("\nStack B :\n");
	print_nb(*stack_b);
}
