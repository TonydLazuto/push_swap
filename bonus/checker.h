/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:26:58 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/09 10:58:35 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
# define CHECKER
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "./libft/libft.h"

typedef struct		s_ins
{
	char			*str;
	struct s_ins	*next;
}					t_ins;

typedef struct		s_num
{
	int				val;
	struct s_num	*next;
}					t_num;

//int		ft_exit(int *nb);
void	ft_error_ins(t_ins *ins);
void	ft_error_nb(int *nb);
int		my_atoi(char *str, int *mynb);

#endif
