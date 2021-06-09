/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:35:37 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/09 10:55:53 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*
int		ft_exit(int *nb)
{
	if (nb)
		free(nb);
	exit(0);
}
*/
void	ft_error_ins(t_ins *ins)
{
	ft_putendl_fd("Error", 1);
/*
 * * while (ins)
 * * {
 * * 	free(ins->str);
 * * 	ins = ins->next;
 * * }
 * * */
	if (ins)
		free(ins);
	exit(0);
}

void	ft_error_nb(int *nb)
{
	ft_putendl_fd("Error", 1);
	if (nb)
		free(nb);
	exit(0);
}
