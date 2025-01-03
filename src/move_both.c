/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:02 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 14:51:52 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest_value(int n, int n2)
{
	if (n2 < n)
		return (n2);
	return (n);
}

static int	get_direction(t_stack *stack, t_cost *cost)
{
	int	rr;
	int	rrr;

	if (cost->index_a == 0 || cost->index_b == 0)
		return (0);
	rr = ((get_least_moves(stack->size_a, cost->index_a) == cost->index_a)
			&& (get_least_moves(stack->size_b, cost->index_b)
				== cost->index_b));
	rrr = ((get_least_moves(stack->size_a, cost->index_a) < cost->index_a)
			&& (get_least_moves(stack->size_b, cost->index_b)
				< cost->index_b));
	return (rr - rrr);
}

static void	move_up(t_stack *stack, t_cost *cost, int loops)
{
	while (loops-- > 0)
	{
		ft_rr(stack, 1);
		cost->index_a--;
		cost->index_b--;
	}
}

static void	move_down(t_stack *stack, t_cost *cost, int loops)
{
	while (loops-- > 0)
	{
		ft_rrr(stack, 1);
		cost->index_a++;
		cost->index_b++;
		if (cost->index_a == stack->size_a)
			cost->index_a = 0;
		if (cost->index_b == stack->size_b)
			cost->index_b = 0;
	}
}

void	move_both(t_stack *stack, t_cost *cost)
{
	int	direction;
	int	loops;

	direction = get_direction(stack, cost);
	if ((cost->cost_a == 0 && cost->cost_b == 0) || direction == 0)
		return ;
	loops = 0;
	if (direction)
		loops = get_smallest_value(cost->cost_a, cost->cost_b);
	ft_printf("Direção: %d\n", direction);
	ft_printf("Loops %d\n", loops);
	if (direction > 0)
		move_up(stack, cost, loops);
	else if (direction < 0)
		move_down(stack, cost, loops);
	ft_printf("index a: %d\n", cost->index_a);
	ft_printf("index b: %d\n", cost->index_b);
}
