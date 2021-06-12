/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:31:49 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/12 11:37:44 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		go_switch(t_num **stack_a, t_num **stack_b, t_ins *ins)
{
	if (!ft_strncmp(ins->str, "sa", 2))
		*stack_a = switch_nb(*stack_a, *stack_b, ins);
	if (!ft_strncmp(ins->str, "sb", 2))
		*stack_b = switch_nb(*stack_b, *stack_a, ins);
	if(!ft_strncmp(ins->str, "ss", 2))
	{
		*stack_a = switch_nb(*stack_a, *stack_b, ins);
		*stack_b = switch_nb(*stack_b, *stack_a, ins);
	}
}

static void		go_push(t_num **stack_a, t_num **stack_b, t_ins *ins)
{

	if (!ft_strncmp(ins->str, "pa", 2))
		push_nb(stack_a, stack_b, ins);
	if (!ft_strncmp(ins->str, "pb", 2))
		push_nb(stack_b, stack_a, ins);
}

static void		go_roll(t_num **stack_a, t_num **stack_b, t_ins *ins)
{
	if (!ft_strncmp(ins->str, "ra", 2))
		*stack_a = roll_stack(*stack_a, *stack_b, ins);
	if (!ft_strncmp(ins->str, "rb", 2))
		*stack_b = roll_stack(*stack_b, *stack_a, ins);
	if (!ft_strncmp(ins->str, "rr", 2))
	{
		*stack_a = roll_stack(*stack_a, *stack_b, ins);
		*stack_b = roll_stack(*stack_b, *stack_a, ins);
	}
}

static void		go_reverse_roll(t_num **stack_a, t_num **stack_b, t_ins *ins)
{
	if (!ft_strncmp(ins->str, "rra", 2))
		*stack_a = reverse_roll_stack(*stack_a, *stack_b, ins);
	if (!ft_strncmp(ins->str, "rrb", 2))
		*stack_b = reverse_roll_stack(*stack_b, *stack_a, ins);
	if (!ft_strncmp(ins->str, "rrr", 2))
	{
		*stack_a = reverse_roll_stack(*stack_a, *stack_b, ins);
		*stack_b = reverse_roll_stack(*stack_b, *stack_a, ins);
	}
}


t_num		*exec_instructions(t_num *nb, t_ins *ins)
{
	t_ins	*next;
	t_num	*stack_a;
	t_num	*stack_b;


	stack_a = nb;
	stack_b = NULL;
	next = NULL;
	while (ins)
	{
		next = ins->next;
		if (!ft_strncmp(ins->str, "sa", 2) || !ft_strncmp(ins->str, "sb", 2) || !ft_strncmp(ins->str, "ss", 2))
			go_switch(&stack_a, &stack_b, ins);
		if (!ft_strncmp(ins->str, "pa", 2) || !ft_strncmp(ins->str, "pb", 2))
			go_push(&stack_a, &stack_b, ins);
	 	if (!ft_strncmp(ins->str, "ra", 2) || !ft_strncmp(ins->str, "rb", 2) || !ft_strncmp(ins->str, "rr", 2))
			go_roll(&stack_a, &stack_b, ins);
		if (!ft_strncmp(ins->str, "rra", 3) || !ft_strncmp(ins->str, "rrb", 3)
				|| !ft_strncmp(ins->str, "rrr", 3))
			go_reverse_roll(&stack_a, &stack_b, ins);	
		
		printf("|--%s--|\nStack A :\n", ins->str);
		print_nb(stack_a);
		printf("\nStack B :\n");
		print_nb(stack_b);
	
		free(ins);
		ins = next;

	}
	return (nb);
}
