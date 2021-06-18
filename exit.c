/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:35:37 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/18 12:22:28 by tonyd            ###   ########.fr       */
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

int		ft_exit(t_num **lst, int *nb)
{
	if (lst)
		empty_lst(lst);
	if (nb)
		free(nb);
	exit(0);
}
