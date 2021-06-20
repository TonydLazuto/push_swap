/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:10 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/20 09:01:35 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The stack asked is LIFO (Last in first out)
**
** sa = swap a - swap the 1st & 2nd element.
** 		If 1 element or none do nothing.
** ss = sa + sb
** pa = push a - take the 1st top "b" element and put it on "a".
** 		If "b" is empty do nothing.
** ra = rotate a - 1st element is now the last.
** rr = ra + rb
** rra = reverse rotate a - Last element is now 1st.
** rrr = rra + rrb
*/

int			*fill_nb(t_num *lst)
{
	int		*nb;
	int		size;
	int		i;

	i = 0;
	nb = NULL;
	size = list_lenght(lst);
	nb = malloc(sizeof(int) * size);
	if (!nb)
		return (NULL);
	while (lst)
	{
		nb[i++] = lst->val;
		lst = lst->next;
	}
	return (nb);
}

void		check_extras(int ac, t_num *stack_a)
{
	int		*nb;
	t_num	*stack_b;

	stack_b = NULL;
	nb = fill_nb(stack_a);
	if (!nb)
		ft_exit(&stack_a, &stack_b,  nb);
	if (ac == 2)
		swap_two(nb);
	if (ac == 3)
		swap_three(nb, &stack_a, &stack_b);
	if (ac == 5)
		swap_five(nb, &stack_a, &stack_b);
	ft_exit(&stack_a, &stack_b, nb);
}

int			push_swap(int ac, char *av[])
{
	t_num	*lst;

	lst = NULL;
	lst = check_args(ac, av, lst);
	check_extras(ac, lst);
	return (0);
}

int			main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	ac -= 1;
	push_swap(ac, av);
	return (0);
}
