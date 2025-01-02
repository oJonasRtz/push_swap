/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/02 11:22:34 by jopereir         ###   ########.fr       */
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

static int	check1(t_stack *stack, t_cost *cost)
{
	return (cost->num_a > max(stack->b, stack->size_b)
		|| cost->num_a < min(stack->b, stack->size_b));
}

void	get_target_b(t_stack *stack, t_cost *cost)
{
	int	i;

	if (check1(stack, cost))
		cost->index_b = get_bigger_index(stack->b, stack->size_b);
	else if (cost->num_a < max(stack->b, stack->size_b)
		&& cost->num_a > min(stack->b, stack->size_b))
	{
		if (cost->num_a > stack->b[0]
			&& cost->num_a < stack->b[stack->size_b - 1])
			cost->index_b = 0;
		else
		{
			i = 1;
			while (i < stack->size_b)
			{
				if (cost->num_a > stack->b[i] && cost->num_a < stack->b[i - 1])
				{
					cost->index_b = i;
					break ;
				}
				i++;
			}
		}
	}
	cost->num_b = stack->b[cost->index_b];
}
