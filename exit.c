/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:35:37 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/06 08:48:27 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_exit(int *nb)
{
	if (nb)
		free(nb);
	exit(0);
}

void	instructions_exit(char *str, int *nb)
{
	ft_putendl_fd(str, 1);
	ft_exit(nb);
}

void	ft_error(int *nb)
{
	ft_putendl_fd("Error", 1);
	ft_exit(nb);
}
