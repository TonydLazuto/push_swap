/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:10 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/07 08:46:51 by tonyd            ###   ########.fr       */
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

void		launch_quick_sort(t_num **stack_a, t_num **stack_b)
{
	int min[2];
	int max[2];
	int pos;
	
	min[0] = 0;
	max[0] = list_length(*stack_a) - 1;

	max[1] = max[0];
	pos = quick_sort(stack_a, stack_b, min[0], max[0]);
/*
	max[0] = pos - 1;
	min[1] = pos + 1;
	//pos = quick_sort(stack_a, stack_b, min[0], max[0]);
	//quick_sort(stack_a, stack_b, pos + 1, max[0]);

//printf("%d : min[1]\n%d : max[1]\n", min[1], max[1]);
	pos = quick_sort(stack_a, stack_b, min[1], max[1]);
	quick_sort(stack_a, stack_b, pos + 1, max[1]);
*/
	//myquick_sort(stack_a, stack_b, min[0], max[0]);
}

void	no_chunk(t_num **stack_a, t_num **stack_b)
{
	t_num	*low;
	t_roll	roll_low;

	while (*stack_a)
	{
		low = get_lowest_val(*stack_a);
		roll_low = get_nb_rolls(*stack_a, low, 'a');
		put_nb_on_top(roll_low, stack_a, stack_b);
		exec_instructions(stack_a, stack_b, "pb");
	}
	while (*stack_b)
		exec_instructions(stack_a, stack_b, "pa");
}

void		pick_swap(int ac, t_num *stack_a)
{
	t_num	*stack_b;

	stack_b = NULL;
	if (ac == 2)
		swap_two(&stack_a, &stack_b);
	else if (ac == 3)
		swap_three(&stack_a, &stack_b);
	else if (ac == 4)
		swap_four(&stack_a, &stack_b);
	else if (ac == 5)
		swap_five(&stack_a, &stack_b);
	else if (ac >= 6 && ac < 30)
		no_chunk(&stack_a, &stack_b);
	else	
		launch_chunk5(&stack_a, &stack_b);

	//else if (ac >= 30 && ac < 100)
	//else if (ac >= 100 && ac < 200)
	//else if (ac >= 200 && ac < 400)
	
	ft_exit(&stack_a, &stack_b);
}

int			main(int ac, char *av[])
{
	t_num	*lst;

 	lst = NULL;
	if (ac == 1)
    {
        av[1] = "9 36 4 15 35 14 29 31 24 2 28 12 20 34 26 25 39 10 27 18 16 6 8 23 38 5 17 3 21 30 33 19 0 1 37 13 32 11 22";
        ac = 3;
		av[2] = NULL;
		//return (0);
    }
    if (!av[2])
	{
        av = split_args(av);
		int len = 0;
		while (av[len])
			len++;
		ac = len;
	}
	ac -= 1;
	lst = check_args(av, lst);
	pick_swap(ac, lst);
	return (0);
}
