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

typedef struct s_num
{
	int				val;
	int				num_chunk;
	struct s_num	*back;
	struct s_num	*next;
}				t_num;

typedef struct s_roll
{
	int			pos;
	const char	*ins;
}				t_roll;

t_num	*new_nb(int val, int num_chunk);
t_num	*last_num(t_num *nb);
int		list_length(t_num *lst);
int		is_point_in_list(t_num *nb, int val);
t_num	*push_back(t_num *list, int val, int num_chunk);
t_num	*push_front(t_num *list, int val, int num_chunk);
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

void	exec_instructions(t_num **stack_a, t_num **stack_b, const char *ins);
t_num	*switch_nb(t_num *cur, const char *ins);
void	push_nb(t_num **cur, t_num **other_stack, const char *ins);
t_num	*roll_stack(t_num *cur, t_num *other_stack, const char *ins);
t_num	*reverse_roll_stack(t_num *cur, t_num *other_stack, const char *ins);

void	print_nb(t_num *nb);
void	print_const(const char *s, int fd);

void	init_roll(t_roll *r);
t_num	*get_lowest_val(t_num *stack_a);
t_num	*get_highest_val(t_num *stack_a);
t_roll	get_nb_rolls(t_num *stack, t_num *elet, char select_stack);
void	put_nb_on_top(t_roll roll, t_num **stack_a, t_num **stack_b);

void	launch_chunk(t_num **stack_a, t_num **stack_b, int ac);
t_num	*assign_chunks(t_num *stack_a, int chunks_size, int nb_chunks);
int		is_chunk_in_stack(t_num *stack, int num_chunk);
void	repush(t_num **stack_a, t_num **stack_b);

#endif
