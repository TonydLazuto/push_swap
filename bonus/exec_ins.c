/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:31:49 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/13 01:31:50 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		go_switch(t_num **stack_a, t_num **stack_b,
							t_ins *elet, t_ins *ins)
{
	if (!ft_strncmp(elet->str, "sa", 2))
		*stack_a = switch_nb(*stack_a, *stack_b, ins);
	if (!ft_strncmp(elet->str, "sb", 2))
		*stack_b = switch_nb(*stack_b, *stack_a, ins);
	if(!ft_strncmp(elet->str, "ss", 2))
	{
		*stack_a = switch_nb(*stack_a, *stack_b, ins);
		*stack_b = switch_nb(*stack_b, *stack_a, ins);
	}
}

static void		go_push(t_num **stack_a, t_num **stack_b,
							t_ins *elet, t_ins *ins)
{
	if (!ft_strncmp(elet->str, "pa", 2))
		push_nb(stack_a, stack_b, ins);
	if (!ft_strncmp(elet->str, "pb", 2))
		push_nb(stack_b, stack_a, ins);
}

static void		go_roll(t_num **stack_a, t_num **stack_b,
							t_ins *elet, t_ins *ins)
{
	if (!ft_strncmp(elet->str, "ra", 2))
		*stack_a = roll_stack(*stack_a, *stack_b, ins);
	if (!ft_strncmp(elet->str, "rb", 2))
		*stack_b = roll_stack(*stack_b, *stack_a, ins);
	if (!ft_strncmp(elet->str, "rr", 2))
	{
		*stack_a = roll_stack(*stack_a, *stack_b, ins);
		*stack_b = roll_stack(*stack_b, *stack_a, ins);
	}
}

static void		go_reverse_roll(t_num **stack_a, t_num **stack_b,
									t_ins *elet, t_ins *ins)
{
	if (!ft_strncmp(elet->str, "rra", 2))
		*stack_a = reverse_roll_stack(*stack_a, *stack_b, ins);
	if (!ft_strncmp(elet->str, "rrb", 2))
		*stack_b = reverse_roll_stack(*stack_b, *stack_a, ins);
	if (!ft_strncmp(elet->str, "rrr", 2))
	{
		*stack_a = reverse_roll_stack(*stack_a, *stack_b, ins);
		*stack_b = reverse_roll_stack(*stack_b, *stack_a, ins);
	}
}


t_num		*exec_instructions(t_num *nb, t_ins *ins)
{
	t_ins	*elet;
	t_num	*stack_a;
	t_num	*stack_b;


	stack_a = nb;
	stack_b = NULL;
	elet = ins;
	while (elet)
	{
		if (!ft_strncmp(elet->str, "sa", 2) || !ft_strncmp(elet->str, "sb", 2) || !ft_strncmp(elet->str, "ss", 2))
			go_switch(&stack_a, &stack_b, elet, ins);
		if (!ft_strncmp(elet->str, "pa", 2) || !ft_strncmp(elet->str, "pb", 2))
			go_push(&stack_a, &stack_b, elet, ins);
	 	if (!ft_strncmp(elet->str, "ra", 2) || !ft_strncmp(elet->str, "rb", 2) || !ft_strncmp(elet->str, "rr", 2))
			go_roll(&stack_a, &stack_b, elet, ins);
		if (!ft_strncmp(elet->str, "rra", 3) || !ft_strncmp(elet->str, "rrb", 3)
				|| !ft_strncmp(elet->str, "rrr", 3))
			go_reverse_roll(&stack_a, &stack_b, elet, ins);
	
		printf("|--%s--|\nStack A :\n", elet->str);
		print_nb(stack_a);
		printf("\nStack B :\n");
		print_nb(stack_b);

		elet = elet->next;
	}
	check_stacks(stack_a, stack_b, ins);
	return (nb);
}
