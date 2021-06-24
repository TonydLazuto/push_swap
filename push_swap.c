/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:10 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/24 13:00:53 by tonyd            ###   ########.fr       */
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

void		check_extras(int ac, t_num *stack_a)
{
	t_num	*stack_b;

	stack_b = NULL;
	if (ac == 2)
		swap_two(&stack_a, &stack_b);
	else if (ac == 3)
		swap_three(&stack_a, &stack_b);
	/*
	else
		swap();
	*/
	get_xtrms(&stack_a, &stack_b);
	/*
	if (ac == 5)
		swap_five(&stack_a, &stack_b);*/
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
