/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:57:54 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/09 13:27:42 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		my_atoi(char *str, int *mynb)
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
		ft_error_nb(mynb);
	return ((int)nb);
}

int			*check_args(int ac, char *av[], int *nb)
{
	int		i;
	int 	j;

	nb = malloc(sizeof(int) * ac);
	if (!nb)
		ft_error_nb(nb);
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
				ft_error_nb(nb);
			j++;
		}
		nb[i - 1] = my_atoi(av[i], nb);
		i++;
	}
	return (nb);
}

int		check_instructions(char *buf)
{
	if (ft_strlen(buf) == 3)
	{
		if (ft_strncmp(buf, "rra", 3) == 0 || ft_strncmp(buf, "rrb", 3) == 0
				|| ft_strncmp(buf, "rrr", 3) == 0)
			return (1);
	}
	if (ft_strlen(buf) == 2)
	{
		if (!ft_strncmp(buf, "sa", 2) || !ft_strncmp(buf, "sb", 2) || !ft_strncmp(buf, "ss", 2)
	 		|| !ft_strncmp(buf, "pa", 2) || !ft_strncmp(buf, "pb", 2)
	 		|| !ft_strncmp(buf, "ra", 2) || !ft_strncmp(buf, "rb", 2) || !ft_strncmp(buf, "rr", 2))
	 	return (1);
	}
	return (0);
}
