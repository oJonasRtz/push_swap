/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:29:28 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 14:22:33 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a(t_stack *stack, int num, int flag)
{
	if (get_least_moves(stack->size_a, num) == num)
		while (num-- > 0)
			ft_ra(stack, flag);
	else
	{
		while (stack->size_a - num++ > 0)
			ft_rra(stack, flag);
	}
}

static	void	move_b(t_stack *stack, int num, int flag)
{
	if (get_least_moves(stack->size_b, num) == num)
		while (num-- > 0)
			ft_rb(stack, flag);
	else
	{
		while (stack->size_b - num++ > 0)
			ft_rrb(stack, flag);
	}
}

void	move_to_top(t_stack *stack, int num, char a_or_b)
{
	if (num > 0)
	{
		if (a_or_b == 'a' || a_or_b == 'A')
			move_a(stack, num, 1);
		else if (a_or_b == 'b' || a_or_b == 'B')
			move_b(stack, num, 1);
		else
			return ;
	}
}
