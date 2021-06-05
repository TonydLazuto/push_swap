/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:10 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/05 08:05:35 by tonyd            ###   ########.fr       */
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

/*
int 		check_doublons()
{
}
*/
int			check_args(int ac, const char *av[])
{
	if (ac == 2)
		swap_one(av);
	/*if (ac == 3)	
		swap_two(av);
	if (ac == 4)	
		swap_three(av);
	if (ac == 6)
		swap_five(av);*/
	return (0);
}
/*
int			push_swap(int ac, char *av[])
{

	return (0);
}
*/
int			main(int ac, const char *av[])
{
	if (ac == 1)
		return (0);
	check_args(ac, av);
	//push_swap(ac, av);
	return (0);
}
