/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:55:19 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/05 12:06:45 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_rr(t_stack *stack, int flag)
{
	ft_rotate(&stack->a, stack->size_a);
	ft_rotate(&stack->b, stack->size_b);
	if (flag)
	{
		stack->ocnt += 2;
		ft_printf("rr\n");
	}
}

void	ft_rrr(t_stack *stack, int flag)
{
	ft_reverse_rotate(&stack->a, stack->size_a);
	ft_reverse_rotate(&stack->b, stack->size_b);
	if (flag)
	{
		stack->ocnt += 2;
		ft_printf("rrr\n");
	}
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
