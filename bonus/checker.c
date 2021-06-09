/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:52:41 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/09 19:41:54 by tonyd            ###   ########.fr       */
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

t_ins		*fill_stack_ins(t_ins *ins, char *line)
{
	int 	valid;
	t_ins	*elet;

	elet = NULL;
	valid = check_instructions(line);
	if (!valid)
		ft_error_ins(&ins);
	elet = new_ins(line);
	if (!elet)
		ft_error_ins(&ins);
	push_back(&ins, elet);
	if (!ins)
		ft_error_ins(&ins);	
	return (ins);
}

void		read_instructions()
{
	int		fd;
	char	*line;
	t_ins	*ins;
	int		res;

	line = NULL;
	ins = NULL;
	res = 1;
	while (res > 0) // voir si fuite memoire si direct si while(gnl())
	{
		res = get_next_line(1, &line);
		if (res > 0)
			ins = fill_stack_ins(ins, line);
		free(line);
	}
	print_ins(ins);	
}

int			checker(int ac, char *av[])
{
	int		*nb;

	nb = NULL;
	nb = check_args(ac, av, nb);
	read_instructions();
	return (0);
}

int			main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	ac -= 1;
	checker(ac, av);
	return (0);
}
