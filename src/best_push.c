/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/02 13:27:32 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_b(t_stack *stack, t_cost *cost)
{
	int	temp;

	temp = get_target_b(stack, cost);
	return (temp);
}

static int	check_a(t_stack *stack, t_cost *cost, int index)
{
	int	move_top;
	int	num;

	num = stack->a[index];
	move_top = get_least_moves(stack->size_a, index);
	cost->num_a = num;
	move_top += check_b(stack, cost);
	return (move_top);
}

static void	check_rr_rrr(t_stack *stack, t_cost *cost)
{
	cost->rr_moves = 0;
	cost->rrr_moves = 0;
	if (cost->index_a != 0 && cost->index_b != 0)
	{
		if (cost->index_a <= stack->size_a / 2
			&& cost->index_b <= stack->size_b / 2)
			cost->rr_moves = get_smaller_value(cost->cost_a, cost->cost_b);
		else if (cost->index_a > stack->size_a / 2
			&& cost->index_b > stack->size_b / 2)
			cost->rrr_moves = get_smaller_value(cost->cost_a, cost->cost_b);
	}
}

static void	init_cost(t_stack *stack, t_cost *cost)
{
	cost->total_cost = INT_MAX;
	cost->index_a = 0;
	cost->num_a = stack->a[0];
	cost->cost_a = 0;
	cost->cost_b = 0;
}

t_cost	check_best_push(t_stack *stack)
{
	t_cost	cost;
	int		i;
	int		temp_a;
	//int		temp_b;

	i = 0;
	init_cost(stack, &cost);
	while (i < stack->size_a)
	{
		temp_a = check_a(stack, &cost, i);
		//temp_b = check_b(stack, &cost);
		if (temp_a + 1 < cost.total_cost)
		{
			cost.total_cost = temp_a + 1;
			cost.cost_a = temp_a;
			cost.cost_b = check_b(stack, &cost);
			cost.index_a = i;
		}
		i++;
	}
	cost.num_a = stack->a[cost.index_a];
	get_target_b(stack, &cost);
	stack->operations_expected += cost.total_cost;
	check_rr_rrr(stack, &cost);
	return (cost);
}