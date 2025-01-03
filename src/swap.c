/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:45:28 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 10:24:13 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int **n, int array_size)
{
	int	temp;

	if (array_size < 2)
		return ;
	temp = (*n)[0];
	(*n)[0] = (*n)[1];
	(*n)[1] = temp;
}

void	ft_sa(t_stack *stack, int flag)
{
	ft_swap(&stack->a, stack->size_a);
	if (flag)
	{
		stack->ocnt++;
		ft_printf("sa\n");
	}
}

void	ft_sb(t_stack *stack, int flag)
{
	ft_swap(&stack->b, stack->size_b);
	if (flag)
	{
		stack->ocnt++;
		ft_printf("sb\n");
	}
}

void	ft_ss(t_stack *stack, int flag)
{
	ft_swap(&stack->a, stack->size_a);
	ft_swap(&stack->b, stack->size_b);
	if (flag)
	{
		stack->ocnt += 2;
		ft_printf("ss\n");
	}
}
