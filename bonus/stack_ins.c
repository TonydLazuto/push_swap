/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:29:27 by tonyd             #+#    #+#             */
/*   Updated: 2021/09/06 18:53:46 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_instructions(char *line)
{
	if (ft_strlen(line) == 3)
	{
		if (!ft_strncmp(line, "rra", 3) || !ft_strncmp(line, "rrb", 3)
			|| !ft_strncmp(line, "rrr", 3))
			return (1);
	}
	if (ft_strlen(line) == 2)
	{
		if (!ft_strncmp(line, "sa", 2) || !ft_strncmp(line, "sb", 2)
			|| !ft_strncmp(line, "ss", 2)
			|| !ft_strncmp(line, "pa", 2) || !ft_strncmp(line, "pb", 2)
			|| !ft_strncmp(line, "ra", 2) || !ft_strncmp(line, "rb", 2)
			|| !ft_strncmp(line, "rr", 2))
			return (1);
	}
	if (!ft_strlen(line))
		return (1);
	return (0);
}

t_ins	*fill_stack_ins(t_ins *ins, char *line, t_num **nb)
{
	int		valid;

	valid = check_instructions(line);
	if (!valid)
		ft_error_ins(&ins, nb);
	if (!ft_strlen(line))
		return (ins);
	ins = push_back_ins(ins, line);
	if (!ins)
		ft_error_ins(&ins, nb);
	return (ins);
}

t_ins	*read_instructions(t_num **nb, t_ins *ins)
{
	char	*line;
	int		res;

	line = NULL;
	res = 1;
	while (res > 0)
	{
		res = get_next_line(STDIN_FILENO, &line);
		if (res == -1)
			ft_error_ins(&ins, nb);
		if (res >= 0)
			ins = fill_stack_ins(ins, line, nb);
		free(line);
	}
	return (ins);
}
