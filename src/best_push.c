/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/02 11:24:13 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_a(t_stack *stack, int num)
{
	int	i;

	if (num == stack->a[0])
		return (0);
	i = 0;
	while (stack->a[i] != num)
		i++;
	return (get_least_moves(stack->size_a, i));
}

static int	check_b(t_stack *stack, int num)
{
	int	i;
	int	j;
	int	cost_up;
	int	cost_down;

	if (num > max(stack->b, stack->size_b)
		|| num < min(stack->b, stack->size_b))
		return (get_least_moves(stack->size_b,
				get_bigger_index(stack->b, stack->size_b)));
	i = 0;
	while (stack->b[i] > num && i < stack->size_b)
		i++;
	j = stack->size_b - 1;
	while (stack->b[j] < num && j >= 0)
		j--;
	cost_up = get_least_moves(stack->size_b, i);
	cost_down = get_least_moves(stack->size_b, j);
	if (cost_down < cost_up)
		return (cost_down);
	return (cost_up);
}

t_cost	check_best_push(t_stack *stack)
{
	t_cost	cost;
	int		i;

	i = 0;
	cost.total_cost = INT_MAX;
	cost.index_a = 0;
	while (i < stack->size_a)
	{
		cost.cost_a = check_a(stack, stack->a[i]);
		cost.cost_b = check_b(stack, stack->a[i]);
		if (cost.cost_a + cost.cost_b + 1 < cost.total_cost)
		{
			cost.total_cost = cost.cost_a + cost.cost_b + 1;
			cost.index_a = i;
			cost.num_a = stack->a[i];
		}
		i++;
	}
	get_target_b(stack, &cost);
	return (cost);
}
