/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:35:37 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/20 09:50:40 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_lst(t_num **nb)
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
}

void	ft_error(t_num **lst1, t_num **lst2)
{
	ft_putendl_fd("Error", 1);
	ft_exit(lst1, lst2);
}

int		ft_exit(t_num **lst1, t_num **lst2)
{
	if (lst1)
		empty_lst(lst1);
	if (lst2)
		empty_lst(lst2);
	exit(0);
}
