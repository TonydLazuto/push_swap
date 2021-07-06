/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:21:07 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/06 18:48:05 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_roll(t_roll *r)
{
	r->pos = 0;
	r->ins = NULL;
}

void	print_const(const char *s, int fd)
{
	int		i;

	i = 0;
	if (!s || fd == 0 || !ft_strlen(s))
		return ;/*
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);*/
}

void		print_nb(t_num *nb)
{
	t_num	*cpy;

	cpy = nb;
	while (cpy)
	{
		if (cpy->val / 10)
		{
			if (cpy->pos / 10)
				printf(" %d -> pos : %d -> true_pos = %d\n", cpy->val, cpy->pos, cpy->true_pos);
			else
				printf(" %d -> pos : %d --> true_pos = %d\n", cpy->val, cpy->pos, cpy->true_pos);
		}
		else
		{
			if (cpy->pos / 10)
				printf(" %d --> pos : %d -> true_pos = %d\n", cpy->val, cpy->pos, cpy->true_pos);
			else
				printf(" %d --> pos : %d --> true_pos = %d\n", cpy->val, cpy->pos, cpy->true_pos);
		}
		cpy = cpy->next;
	}
}
