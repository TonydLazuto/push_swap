/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:10 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/25 09:54:41 by tonyd            ###   ########.fr       */
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


void	pop_xtrms(t_num **stack_a, t_num **stack_b)
{
	t_num	*elet;
	t_num	*elet2;
	t_roll	roll;

	elet = *stack_a;
	elet2 = *stack_a;
	elet = get_lowest(*stack_a, elet);
	roll = get_nb_rolls(*stack_a, elet);
	//printf("lowest number : %d\nnb : %d\nins : %s\n",
				//elet->val, roll.nb, roll.ins);
	elet2 = get_greatest(*stack_a, elet2);
	roll = get_nb_rolls(*stack_a, elet2);
	//printf("gtest number : %d\nnb : %d\nins : %s\n",
				//elet2->val, roll.nb, roll.ins);
	print_nb(*stack_a);
}

void		check_extras(int ac, t_num *stack_a)
{
	t_num	*stack_b;

	stack_b = NULL;
	if (ac == 2)
		swap_two(&stack_a, &stack_b);
	else if (ac == 3)
		swap_three(&stack_a, &stack_b);
	else if (ac == 4)
		swap_four(&stack_a, &stack_b);
	else if (ac == 5)
		swap_five(&stack_a, &stack_b);
	/*
	else
		swap();
	*/
	//pop_xtrms(&stack_a, &stack_b);
	print_nb(stack_a);
	ft_exit(&stack_a, &stack_b);
}

int			main(int ac, char *av[])
{
	t_num	*lst;

	lst = NULL;
	if (ac == 1)
		return (0);
	ac -= 1;
	lst = check_args(ac, av, lst);
	check_extras(ac, lst);
	return (0);
}
