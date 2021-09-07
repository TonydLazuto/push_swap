/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:57:54 by tonyd             #+#    #+#             */
/*   Updated: 2021/09/06 19:16:38 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_value_exist(char *str, t_num *mynb)
{
	if (!ft_strlen(str))
		{printf("YO1\n");ft_error_nb(&mynb);}
}

int	my_atoi(char *str, t_num *mynb)
{
	int			sign;
	long long	nb;

	check_value_exist(str, mynb);
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
		{printf("YO2\n");ft_error_nb(&mynb);}
	return ((int) nb);
}

void	check_duplicate(t_num *nb, int val)
{
	if (is_point_in_list(nb, val))
		{printf("YO3\n");ft_error_nb(&nb);}
}

t_num	*check_args(int ac, char *av[], t_num *nb)
{
	int	i;
	int	j;
	int	val;

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
				{printf("YO4\n");ft_error_nb(&nb);}
			j++;
		}
		val = my_atoi(av[i], nb);
		check_duplicate(nb, val);
		nb = push_back(nb, val);
		if (!nb)
			{printf("YO5\n");ft_error_nb(&nb);}
		i++;
	}
	return (nb);
}
