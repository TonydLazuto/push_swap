/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:52:41 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/11 08:31:12 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

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

void		print_ins(t_ins *ins)
{
	t_ins	*cpy;

	cpy = ins;
	while (cpy)
	{
		printf("|%s|\n", cpy->str);
		cpy = cpy->next;
	}
}

int			main(int ac, char *av[])
{
	t_num	*nb;

	nb = NULL;
	if (ac == 1)
		return (0);
	ac -= 1;
	nb = check_args(ac, av, nb);
	read_instructions(nb);
	return (0);
}
