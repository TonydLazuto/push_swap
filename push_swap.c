/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:10 by tonyd             #+#    #+#             */
/*   Updated: 2021/09/06 18:54:26 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The stack asked is LIFO (Last in first out)
**
** sa = swap a - swap the 1st & 2nd element.
** 		If 1 element or none do nothing.
** ss = sa + sb
** pa = push a - take the 1st top "b" element and put it on "a".
** 		If "b" is empty do nothing.
** ra = rotate a - 1st element is now the last.
** rr = ra + rb
** rra = reverse rotate a - Last element is now 1st.
** rrr = rra + rrb
*/

int	check_already_sorted(t_num *stack_a)
{
	t_num	*cpy;

	cpy = stack_a;
	while (cpy)
	{
		if (cpy->next && cpy->val > cpy->next->val)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

void	no_chunk(t_num **stack_a, t_num **stack_b)
{
	t_num	*low;
	t_roll	roll_low;

	while (*stack_a)
	{
		low = get_lowest_val(*stack_a);
		roll_low = get_nb_rolls(*stack_a, low, 'a');
		put_nb_on_top(roll_low, stack_a, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
	}
	while (*stack_b)
		exec_instructions(stack_a, stack_b, "pa");
}

void	pick_swap(int ac, t_num *stack_a)
{
	t_num	*stack_b;

	stack_b = NULL;
	if (check_already_sorted(stack_a))
		return ;
	if (ac == 2)
		swap_two(&stack_a, &stack_b);
	else if (ac == 3)
		swap_three(&stack_a, &stack_b);
	else if (ac == 4)
		swap_four(&stack_a, &stack_b);
	else if (ac == 5)
		swap_five(&stack_a, &stack_b);
	else if (ac >= 6 && ac < 30)
		no_chunk(&stack_a, &stack_b);
	else
		launch_chunk(&stack_a, &stack_b, ac);
	ft_exit(&stack_a, &stack_b);
}

int	main(int ac, char *av[])
{
	t_num	*lst;
	int		len;

	len = 0;
	lst = NULL;
	if (!av[2])
	{
		av = split_args(av);
		while (av[len])
			len++;
		ac = len;
	}
	ac -= 1;
	lst = check_args(av, lst);
	pick_swap(ac, lst);
	return (0);
}
