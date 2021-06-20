/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:16 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/20 08:57:24 by tonyd            ###   ########.fr       */
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
int		ft_exit(t_num **lst1, t_num **lst2, int *nb);
void	ft_error(t_num **lst1, t_num **lst2, int *nb);

void	swap_two(int *nb);
void	swap_three(int *nb, t_num **stack_a, t_num **stack_b);
void	swap_five(int *nb, t_num **stack_a, t_num **stack_b);

void	exec_instructions(t_num **stack_a, t_num **stack_b,
								const char *ins);
t_num	*switch_nb(t_num *cur, t_num *other_stack, const char *ins);
void	push_nb(t_num **cur, t_num **other_stack, const char *ins);
t_num	*roll_stack(t_num *cur, t_num *other_stack, const char *ins);
t_num	*reverse_roll_stack(t_num *cur, t_num *other_stack, const char *ins);

void	print_nb(t_num *nb);
void	print_const(const char *s, int fd);

#endif
