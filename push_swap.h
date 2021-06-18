/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:16 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/18 11:30:27 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct		s_num
{
	int				val;
	struct s_num	*next;
}					t_num;

t_num	*new_nb(int val);
t_num	*last_num(t_num *nb);
int		list_lenght(t_num *lst);
int		is_point_in_list(t_num *nb, int val);
t_num	*push_back(t_num *list, int val);
t_num	*push_front(t_num *list, int val);
t_num	*pop_back(t_num *list);
t_num	*pop_front(t_num *list);

int		my_atoi(char *str, t_num *mynb);
void	check_duplicate(t_num *nb, int val);
t_num	*check_args(int ac, char *av[], t_num *nb);

void	empty_lst(t_num **nb);
int		ft_exit(t_num **lst, int *nb);
void	ft_error(t_num **lst, int *nb);

void	swap_two(int *nb);
void	swap_three(int *nb, int ac);
void	swap_five(int *nb, int ac);

#endif
