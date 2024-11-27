/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:49:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/27 12:45:55 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

void	ft_swap(int *n, int array_size);
void	ft_push(int **src, int **dest, int array_size);
int		*stack_init(char **s, int *size);
int		isalldigit(char **s);
int		ft_arraylen(int *a);
int		*arraydown(int *n, int array_size);
int		*arrayup(int *n, int array_size);
void	ft_rotate(int *n, int array_size);
void	ft_reverse_rotate(int *n, int array_size);
int		isduplicate(char **s);
int		islargerthan_limits(char **s);

#endif