/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:35:37 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/09 19:49:38 by tonyd            ###   ########.fr       */
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
void	ft_error_ins(t_ins **ins)
{
	t_ins *next;

	next = NULL;
	ft_putendl_fd("Error", 1);
	if (*ins)
	{
		while (*ins)
		{
			next = (*ins)->next;
			free(*ins);
			*ins = next;
   		}
	}
	exit(0);
}

void	ft_error_nb(int *nb)
{
	ft_putendl_fd("Error", 1);
	if (nb)
		free(nb);
	exit(0);
}
