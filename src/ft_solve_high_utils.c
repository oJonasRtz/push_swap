/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/28 14:06:27 by jopereir         ###   ########.fr       */
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

int	check_best_push(t_stack *stack)
{
	// int	i;
	// int	cost;
	// int	best_cost;
	// int	best_index;

	// i = 0;
	// best_cost = INT_MAX;
	// best_index = -1;
	// while (i < stack->size_a)
	// {
	// 	cost = get_least_moves(stack->size_a, i);
	// 	if (cost < best_cost)
	// 	{
	// 		best_cost = cost;
	// 		best_index = i;
	// 	}
	// 	i++;
	// }
	return (stack->a[0]);
}
