/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:52:41 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/07 14:24:26 by tonyd            ###   ########.fr       */
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

int			*check_args(int ac, char *av[], int *nb)
{
	int		i;
	int 	j;

	nb = malloc(sizeof(int) * ac);
	if (!nb)
		ft_error(nb);
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
				ft_error(nb);
			j++;
		}
		nb[i - 1] = my_atoi(av[i], nb);
		printf("nb_%d = %d\n", i-1,nb[i-1]);
		i++;
	}
	return (nb);
}

void		read_instructions()
{
	int		fd;
	char	buf[3];
	ssize_t	ret;

	ret = read(1, buf, 3);
	buf[ret] = '\0';
	while (ret)
	{
		ret = read(1, buf, 3);
		buf[ret] = '\0';
	}
}

int			checker(int ac, char *av[])
{
	int		*nb;

	nb = NULL;
	nb = check_args(ac, av, nb);
	read_instructions();
	printf("%s\n", INSTRUCTS);
	return (0);
}

int			main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	ac -= 1;
	checker(ac, av);
	return (0);
}
