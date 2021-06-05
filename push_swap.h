/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:53:16 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/05 11:14:08 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647


int		ft_exit(int *nb);
void	ft_error(int *nb);
int		my_atoi(const char *str, int *mynb);
int		*check_args(int ac, const char *av[], int *nb);
//void	check_duplicate(int ac, int *nb);
void	swap_two(int *nb);
void	swap_three(int *nb);

#endif
