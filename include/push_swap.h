/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:49:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 15:40:23 by jopereir         ###   ########.fr       */
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
void	ft_rotate(int *n, int array_size);
void	ft_reverse_rotate(int *n, int array_size);
int		isduplicate(char **s);
int		islargerthan_limits(char **s);
int		already_sorted(char **s);
void	ft_least_moves(int *a, int *b, int array_size);
char	*ft_sa(int *a, int array_size);
int		issorted(int *n, int array_size);
int		get_bigger_num(int *n, int array_size);
int		get_smaller_num(int *n, int array_size);
char	*ft_get_strcat(char *s1, char *s2);
char	*ft_case3(int **a, int size);
char	*ft_rra(int *a, int array_size);
char	*ft_ra(int *a, int array_size);
char	*ft_pb(int *a, int *b, int array_size);
char	*ft_pa(int *a, int *b, int array_size);
char	*ft_case5(int **a, int **b, int size);

#endif