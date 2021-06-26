/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:57:54 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/26 11:40:39 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			my_atoi(char *str, t_num *mynb)
{
	int			sign;
	long long	nb;

	nb = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		if (nb < 0 && sign == -1)
			return (0);
		if (nb < 0 && sign == 1)
			return (-1);
		str++;
	}
	nb *= sign;
	if (nb > INT_MAX || nb < INT_MIN)
		ft_error(&mynb, NULL);
	return ((int)nb);
}

void		check_duplicate(t_num *nb, int val)
{
	if (is_point_in_list(nb, val))
		ft_error(&nb, NULL);
}

t_num		*check_args(int ac, char *av[], t_num *nb)
{
	int		i;
	int 	j;
	int		val;

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
				ft_error(&nb, NULL);
			j++;
		}
		val = my_atoi(av[i], nb);
		check_duplicate(nb, val);
		nb = push_back(nb, val);
		if (!nb)
			ft_error(&nb, NULL);
		i++;
	}
	return (nb);
}
