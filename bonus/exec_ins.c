/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:31:49 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/11 09:49:31 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		go_switch(t_num **stack_a, t_num **stack_b, t_ins *ins)
{
	if (!ft_strncmp(ins, "sa", 2))
		switch_nb(stack_a);
	if (!ft_strncmp(ins, "sb", 2))
		switch_nb(stack_b);
	if(!ft_strncmp(ins, "ss", 2))
	{
		switch_nb(stack_a);
		switch_nb(stack_b);
	}
}

void		go_push(t_num **stack_a, t_num **stack_b, t_ins *ins)
{

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
		if (!ft_strncmp(ins, "sa", 2) || !ft_strncmp(ins, "sb", 2) || !ft_strncmp(ins, "ss", 2))
			go_switch(&stack_a, &stack_b, ins);
		if (!ft_strncmp(ins, "pa", 2) || !ft_strncmp(ins, "pb", 2))
			go_push(&stack_a, &stack_b, ins);
	 	if (!ft_strncmp(ins, "ra", 2) || !ft_strncmp(ins, "rb", 2) || !ft_strncmp(ins, "rr", 2))
			go_roll(&stack_a, &stack_b, ins);
		if (!ft_strncmp(ins, "rra", 3) || !ft_strncmp(ins, "rrb", 3)
				|| !ft_strncmp(ins, "rrr", 3))
			go_reverse_roll(&stack_a, &stack_b, ins);
		free(ins);
		ins = next;
	}
	return (nb);
}
