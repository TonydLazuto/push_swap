/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:52:41 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/10 09:04:39 by tonyd            ###   ########.fr       */
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

int		check_instructions(char *line)
{
	if (ft_strlen(line) == 3)
	{
		if (ft_strncmp(line, "rra", 3) == 0 || ft_strncmp(line, "rrb", 3) == 0
				|| ft_strncmp(line, "rrr", 3) == 0)
			return (1);
	}
	if (ft_strlen(line) == 2)
	{
		if (!ft_strncmp(line, "sa", 2) || !ft_strncmp(line, "sb", 2) || !ft_strncmp(line, "ss", 2)
	 		|| !ft_strncmp(line, "pa", 2) || !ft_strncmp(line, "pb", 2)
	 		|| !ft_strncmp(line, "ra", 2) || !ft_strncmp(line, "rb", 2) || !ft_strncmp(line, "rr", 2))
	 	return (1);
	}
	return (0);
}

t_ins		*fill_stack_ins(t_ins *ins, char *line, t_num *nb)
{
	int 	valid;
	t_ins	*elet;

	elet = NULL;
	valid = check_instructions(line);
	if (!valid)
		ft_error_ins(&ins, &nb);
	elet = new_ins(line);
	if (!elet)
		ft_error_ins(&ins, &nb);
	push_back_ins(&ins, elet);
	if (!ins)
		ft_error_ins(&ins, &nb);
	return (ins);
}

void		read_instructions(t_num *nb)
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
			ins = fill_stack_ins(ins, line, nb);
		free(line);
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
