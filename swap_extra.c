/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:42:08 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/05 08:25:30 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_nb(const char *str)
{
	int		nb;
	int		i;

	if (str[0] == '-' || str[0] == '+')
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		i++;
	}
	nb = ft_atoi(str);
	return (nb);
}

void	swap_one(const char *av[])
{
	int		nb;

	nb = get_nb(av[1]);
	printf("nb = %d\n", nb);
	ft_putendl_fd("sa", 1);
	ft_exit();
}
