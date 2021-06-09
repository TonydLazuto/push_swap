/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:42:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/09 09:19:00 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(int *nb)
{
	if (nb[0] > nb[1])
		ft_putendl_fd("sa", 1);
	else if (nb[0] == nb[1])
		ft_error(nb);
}

void	swap_three(int *nb, int ac)
{
	if (nb[0] == nb[1] || nb[1] == nb[2] || nb[2] == nb[0])
		ft_error(nb);
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[2] > nb[0])
		ft_putendl_fd("sa", 1);
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[2] < nb[0])
		ft_putendl_fd("ra", 1);
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[2] < nb[0])
		ft_putendl_fd("rra", 1);
	else if (nb[0] > nb[1] && nb[1] > nb[2] && nb[2] < nb[0])
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("rra", 1);	
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[2] > nb[0])
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("ra", 1);
	}
	if (ac == 3)
		ft_exit(nb);
}

void	swap_five(int *nb, int ac)
{
	;
}
