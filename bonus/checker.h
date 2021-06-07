/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:26:58 by tonyd             #+#    #+#             */
/*   Updated: 2021/06/07 14:12:57 by tonyd            ###   ########.fr       */
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
# define INSTRUCTS "sa sb ss pa pb ra rb rr rra rrb rrr"

int		ft_exit(int *nb);
void	ft_error(int *nb);
int		my_atoi(char *str, int *mynb);

#endif
