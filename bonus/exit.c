/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:35:37 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/10 09:41:24 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*
int		ft_exit(int *nb)
{
	if (nb)
		free(nb);
	exit(0);
}
*/
void	ft_error_ins(t_ins **ins, t_num **nb)
{
	t_ins *next;

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
	if (*nb)
		ft_error_nb(nb);
	else
		ft_putendl_fd("Error", 1);
	exit(0);
}

void	ft_error_nb(t_num **nb)
{
	t_num *next;

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
	ft_putendl_fd("Error", 1);
	exit(0);
}
