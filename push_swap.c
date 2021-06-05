/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:10 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/05 11:25:17 by tonyd            ###   ########.fr       */
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

void		check_extras(int ac, int *nb)
{
	if (ac == 2)	
		swap_two(nb);
	if (ac == 3)	
		swap_three(nb);
	//if (ac == 5)
		//swap_five(nb);
	ft_exit(nb);
}

int			push_swap(int ac, const char *av[])
{
	int *nb;

	nb = NULL;
	nb = check_args(ac, av, nb);
	check_extras(ac, nb);
	return (0);
}

int			main(int ac, const char *av[])
{
	if (ac == 1)
		return (0);
	ac -= 1;
	push_swap(ac, av);
	return (0);
}
