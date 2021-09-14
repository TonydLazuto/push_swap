/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:26:58 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/17 17:42:06 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "./../libft/libft.h"
# include "./get_next_line.h"

typedef struct s_ins
{
	char			*str;
	struct s_ins	*next;
}				t_ins;

typedef struct s_num
{
	int				val;
	struct s_num	*next;
}				t_num;

void	print_ins(t_ins *ins);
void	print_nb(t_num *nb);

int		ft_exit(t_num **stack_1, t_num **stack_2, t_ins *ins);
void	ft_ko(t_num **stack_1, t_num **stack_2, t_ins *ins);
void	empty_nb(t_num **nb);
void	empty_ins(t_ins **ins);
void	ft_error_ins(t_ins **ins, t_num **nb);
void	ft_error_nb(t_num **nb);
void	ft_error(t_num **stack_1, t_num **stack_2, t_ins *ins);

int		check_instructions(char *line);
t_ins	*new_ins(char *str);
t_ins	*fill_stack_ins(t_ins *ins, char *line, t_num **nb);
t_ins	*read_instructions(t_num **nb, t_ins *ins);
t_ins	*last_ins(t_ins *ins);
t_ins	*push_back_ins(t_ins *list, char *line);
int		my_atoi(char *str, t_num *mynb);
t_num	*check_args(char *av[], t_num *nb);
t_num	*new_nb(int val);
t_num	*last_num(t_num *nb);
int		is_point_in_list(t_num *nb, int val);
t_num	*push_back(t_num *list, int val);
t_num	*push_front(t_num *list, int val);
t_num	*pop_back(t_num *list);
t_num	*pop_front(t_num *list);
t_num	*exec_instructions(t_num *nb, t_ins *ins);
t_num	*switch_nb(t_num *cur, t_num *other_stack, t_ins *ins);
void	push_nb(t_num **cur, t_num **other_stack, t_ins *ins);
t_num	*roll_stack(t_num *cur, t_num *other_stack, t_ins *ins);
t_num	*reverse_roll_stack(t_num *cur, t_num *other_stack, t_ins *ins);
void	check_stacks(t_num *stack_a, t_num *stack_b, t_ins *ins);

#endif
