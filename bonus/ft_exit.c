/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:35:37 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/13 00:42:04 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	empty_nb(t_num **nb)
{
	t_num	*next;

	next = NULL;
	if (*nb)
	{
		while (*nb)
		{
			next = (*nb)->next;
			free(*nb);
			*nb = next;
		}
	}
}

void	empty_ins(t_ins **ins)
{
	t_ins	*next;

	next = NULL;
	if (*ins)
	{
		while (*ins)
		{
			next = (*ins)->next;
			free(*ins);
			*ins = next;
		}
	}
}

int	ft_exit(t_num **stack_1, t_num **stack_2, t_ins *ins)
{
	empty_nb(stack_1);
	empty_nb(stack_2);
	empty_ins(&ins);
	exit(0);
}
