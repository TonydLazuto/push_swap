/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:52:41 by tonyd             #+#    #+#             */
/*   Updated: 2021/09/06 19:01:18 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

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

void    print_ins(t_ins *ins)
{
        t_ins   *cpy;

        cpy = ins;
        while (cpy)
        {
                printf("|%s|\n", cpy->str);
                cpy = cpy->next;
        }
}

void    print_nb(t_num *nb)
{
        t_num   *cpy;

        cpy = nb;
        while (cpy)
        {
                printf("|%d|\n", cpy->val);
                cpy = cpy->next;
        }
}

void	check_stacks(t_num *stack_a, t_num *stack_b, t_ins *ins)
{
	t_num	*elet;

	elet = stack_a;
	if (stack_b)
		{printf("YO100\n");ft_ko(&stack_a, &stack_b, ins);}
	while (elet)
	{
		if (elet->next)
		{
			if (elet->val > elet->next->val)
				ft_ko(&stack_a, &stack_b, ins);
		}
		elet = elet->next;
	}
	ft_putendl_fd("OK", 1);
	ft_exit(&stack_a, &stack_b, ins);
}

int	main(int ac, char *av[])
{
	t_num	*nb;
	t_ins	*ins;

	nb = NULL;
	ins = NULL;
	if (ac == 1)
		return (0);
	ac -= 1;
	nb = check_args(ac, av, nb);
	ins = read_instructions(&nb, ins);
	nb = exec_instructions(nb, ins);
	return (0);
}
