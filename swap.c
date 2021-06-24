/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 01:12:24 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/24 15:59:43 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*get_lowest(t_num *stack_a, t_num *elet)
{
	int		valid;
	t_num	*tmp;
	int		size;

	tmp = NULL;
	size = list_length(stack_a);
	while (elet)
	{
		tmp = stack_a;
		valid = 1;
		while (tmp)
		{
			if (elet->val < tmp->val)
				valid++;
			tmp = tmp->next;
		}
		if (valid == size)
			return (elet);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet);
}
t_num	*get_greatest(t_num *stack_a, t_num *elet)
{
	int		valid;
	t_num	*tmp;
	int		size;

	tmp = NULL;
	size = list_length(stack_a);
	while (elet)
	{
		tmp = stack_a;
		valid = 1;
		while (tmp)
		{
			if (elet->val > tmp->val)
				valid++;
			tmp = tmp->next;
		}
		if (valid == size)
			return (elet);
		elet = elet->next;
	}
	elet = last_num(stack_a);
	return (elet);
}

void	get_xtrms(t_num **stack_a, t_num **stack_b)
{
	t_num	*elet;
	t_num	*elet2;

	elet = get_lowest(*stack_a, elet);
	printf("lowest number: %d\n", elet->val);
	elet2 = get_greatest(*stack_a, elet2);
	printf("Greatest number: %d\n", elet2->val);
}
