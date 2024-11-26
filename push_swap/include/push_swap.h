/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:49:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:59:22 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	ft_swap(int *n);
void	ft_push(int **src, int **dest);
int		*stack_init(char **s);
int		isalldigit(char *s);
int		ft_arraylen(int *a);
int		*arraydown(int *n);
int		*arrayup(int *n);
void	ft_double_free(int *a, int *b);

#endif