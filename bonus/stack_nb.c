/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:57:54 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/10 09:03:46 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		my_atoi(char *str, t_num *mynb)
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
	if (nb > INT32_MAX || nb < INT32_MIN)
		ft_error_nb(&mynb);
	return ((int)nb);
}

t_num		*fill_stack_nb(t_num *nb, int val)
{
	t_num	*elet;

	elet = new_nb(val);
	if (!elet)
		ft_error_nb(&nb);
	push_back(&nb, elet);
	if (!nb)
		ft_error_nb(&nb);
	return (nb);
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
				ft_error_nb(&nb);
			j++;
		}
		val = my_atoi(av[i], nb);
		nb = fill_stack_nb(nb, val);
		i++;
	}
	return (nb);
}
