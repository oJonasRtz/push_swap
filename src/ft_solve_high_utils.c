/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 10:50:07 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_least_moves(int size, int index)
{
	if (size - index < index)
		return (size - index);
	return (index);
}

int	max(int *stack, int size)
{
	return (stack[get_bigger_index(stack, size)]);
}

int	min(int *stack, int size)
{
	return (stack[get_smaller_index(stack, size)]);
}

int	check1(t_stack *stack, t_cost *cost, int flag)
{
	if (flag)
		return (cost->num_a > max(stack->b, stack->size_b)
			|| cost->num_a < min(stack->b, stack->size_b));
	return (cost->num_a > stack->b[0]
		&& cost->num_a < stack->b[stack->size_b - 1]);
}

int	get_target_b(t_stack *stack, t_cost *cost)
{
	int	i;

	if (check1(stack, cost, 1))
		cost->index_b = get_bigger_index(stack->b, stack->size_b);
	else if (cost->num_a < max(stack->b, stack->size_b)
		&& cost->num_a > min(stack->b, stack->size_b))
	{
		if (check1(stack, cost, 0))
			cost->index_b = 0;
		else
		{
			i = 1;
			while (i < stack->size_b
				&& !(cost->num_a > stack->b[i]
					&& cost->num_a < stack->b[i - 1]))
				i++;
			cost->index_b = i;
		}
	}
	cost->num_b = stack->b[cost->index_b];
	return (cost->index_b);
}
