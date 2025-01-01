/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/28 14:07:55 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_pos_b(t_stack *stack, int	num)
{
	if (num > max(stack->b, stack->size_b)
		|| num < min(stack->b, stack->size_b))
		move_to_top(stack, get_bigger_index(stack->b, stack->size_b), 'b');
	else if (num < max(stack->b, stack->size_b)
		&& num > min(stack->b, stack->size_b))
	{
		if (num > stack->b[stack->size_b / 2])
			while (!(num > stack->b[0] && num < stack->b[stack->size_b - 1]))
				ft_rb(stack, 1);
		else
			while (!(num > stack->b[0] && num < stack->b[stack->size_b - 1]))
				ft_rrb(stack, 1);
	}
}

static void	sort_a(t_stack *stack)
{
	if (!already_sorted(stack, 0, stack->size_a))
		tiny_sort(stack);
	if (stack->a[2] > stack->b[0])
		ft_rra(stack, 1);
}

static void	sort_b(t_stack *stack)
{
	t_cost	cost;

	cost = check_best_push(stack);
	move_both(stack, &cost);
	//move_to_top(stack, cost.index_a, 'a');
	//check_pos_b(stack, stack->a[0]);
	ft_pb(stack, 1);
	if (stack->size_a == 3)
	{
		move_to_top(stack, get_bigger_index(stack->b, stack->size_b), 'b');
		return ;
	}
	return (sort_b(stack));
}

static void	push_to_a(t_stack *stack)
{
	int	last_a;

	last_a = stack->a[stack->size_a - 1];
	if (last_a > stack->b[0]
		&& last_a != max(stack->a, stack->size_a))
		ft_rra(stack, 1);
	else
		ft_pa(stack, 1);
	if (stack->size_b == 0)
		return ;
	return (push_to_a(stack));
}

void	large_sort(t_stack *stack)
{
	double_operation(stack, &ft_pb, 2, 1);
	sort_b(stack);
	sort_a(stack);
	push_to_a(stack);
	if (get_smaller_index(stack->a, stack->size_a) != 0)
		move_to_top(stack, get_smaller_index(stack->a, stack->size_a), 'a');
}
