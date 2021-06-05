/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 08:54:03 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/05 11:11:22 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*check_args(int ac, const char *av[], int *nb)
{
	int		i;
	int 	j;

	nb = malloc(sizeof(int) * ac);
	if (!nb)
		ft_error(nb);
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-' || av[i][0] == '+')
			j = 1;
		else
			j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				ft_error(nb);
			j++;
		}
		nb[i - 1] = my_atoi(av[i], nb);
		printf("nb_%d = %d\n", i-1,nb[i-1]);
		i++;
	}
	return (nb);
}
