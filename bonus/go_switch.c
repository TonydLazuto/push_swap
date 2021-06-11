/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:45:02 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/11 09:19:55 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num	*switch_nb(t_num **cur, t_num **other_stack, t_ins *ins)
{
	int		val;
	t_ins	*tmp;

	tmp = NULL;
	if (*cur && (*cur)->next)
	{
		val = (*cur)->val;
		(*cur)->val = (*cur)->next->val;
		(*cur)->next->val = val;
		tmp = (*cur)->next;
		(*cur)->next = (*cur)->next->next;
		(*cur)->next->next = tmp;
	}
	else
		ft_exit(cur, other_stack, ins);
	return(cur);
}

