/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:16 by tonyd             #+#    #+#             */
/*   Updated: 2021/07/09 17:50:26 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
/*
typedef struct		s_list
{
	int				len;
	struct s_num	*first;
	struct s_num	*last;
}					t_list;
*/
typedef struct		s_num
{
	int				val;
	int				pos;
	int				true_pos;
	struct s_num	*back;
	struct s_num	*next;
}					t_num;

typedef	struct	s_roll
{
	int			pos;
	const char	*ins;
}				t_roll;

t_num	*new_nb(int val, int pos, int true_pos);
t_num	*begin_num(t_num *nb);
t_num	*last_num(t_num *nb);
int		list_length(t_num *lst);
int		is_point_in_list(t_num *nb, int val);
t_num	*push_back(t_num *list, int val, int pos, int true_pos);
t_num	*push_front(t_num *list, int val, int pos, int true_pos);
t_num	*pop_back(t_num *list);
t_num	*pop_front(t_num *list);
void	clear_lst(t_num **lst);

int		my_atoi(char *str, t_num *mynb);
void	check_duplicate(t_num *nb, int val);
t_num	*check_args(char *av[], t_num *nb);
char	**split_args(char *av[]);

void	empty_lst(t_num **nb);
int		ft_exit(t_num **lst1, t_num **lst2);
void	ft_error(t_num **lst1, t_num **lst2);

void	swap_two(t_num **stack_a, t_num **stack_b);
void	swap_three(t_num **stack_a, t_num **stack_b);
void	swap_four(t_num **stack_a, t_num **stack_b);
void	swap_five(t_num **stack_a, t_num **stack_b);

void	exec_instructions(t_num **stack_a, t_num **stack_b,
								const char *ins);
t_num	*switch_nb(t_num *cur, const char *ins);
void	push_nb(t_num **cur, t_num **other_stack, const char *ins);
t_num	*roll_stack(t_num *cur, t_num *other_stack, const char *ins);
t_num	*reverse_roll_stack(t_num *cur, t_num *other_stack, const char *ins);

void	print_nb(t_num *nb);
void	print_const(const char *s, int fd);

void	init_roll(t_roll *r);
t_num	*get_lowest(t_num *stack_a);
t_num	*get_greatest(t_num *stack_a);
t_roll	get_nb_rolls(t_num *stack, t_num *elet, char select);
void	put_nb_on_top(t_roll roll, t_num **stack_a, t_num **stack_b);

void	myquick(t_num **stack_a, t_num **stack_b);
void	set_num_pos(t_num **stack);
t_num	*get_nb_by_pos(int pos, t_num *stack);
t_num	*get_nb_by_val(int val, t_num *stack);
t_num	*get_pivot(t_num **stack_a, t_num **stack_b, int min, int max);
int		get_lowest_pos(t_num *stack_a);
t_num	*get_sub_lst(t_num **stack_a, t_num **stack_b, int min, int max);
void	resort(t_num **stack_a, t_num **stack_b, int last_min_val);



#endif
