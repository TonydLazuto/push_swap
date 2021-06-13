/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 00:33:09 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/13 00:46:39 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error_ins(t_ins **ins, t_num **nb)
{
	empty_ins(ins);
	if (*nb)
		ft_error_nb(nb);
	else
		ft_putendl_fd("Error", 1);
	exit(0);
}

void	ft_error_nb(t_num **nb)
{
	empty_nb(nb);
	ft_putendl_fd("Error", 1);
	exit(0);
}

void	ft_error(t_num **stack_1, t_num **stack_2, t_ins *ins)
{
	ft_putendl_fd("Error", 1);
	ft_exit(stack_1, stack_2, ins);
}
