/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:21:07 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/24 18:50:28 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_roll(t_roll *r)
{
	r->nb = 0;
	r->ins = NULL;
}

void	free_roll_ins(t_roll *r)
{
	free(r->ins);
	r->ins = NULL;
}

void	print_const(const char *s, int fd)
{
	int		i;

	i = 0;
	if (!s || fd == 0)
		return ;
	ft_putchar_fd('!', 1);
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('!', 1);
	ft_putchar_fd('\n', fd);
}

void		print_nb(t_num *nb)
{
	t_num	*cpy;

	cpy = nb;
	while (cpy)
	{
		printf("|%d|\n", cpy->val);
		cpy = cpy->next;
	}
}
