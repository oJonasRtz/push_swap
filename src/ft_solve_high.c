/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 14:38:56 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_stack *stack)
{
	int	max_a;

	tiny_sort(stack);
	max_a = stack->a[2];
	if (max_a > stack->b[0])
		ft_rra(stack, 1);
}

static void	sort_b(t_stack *stack)
{
	t_cost	cost;

	cost = check_best_push(stack);
	show_stack(stack->a, stack->size_a, "Sack A: ");
	show_stack(stack->b, stack->size_b, "Sack B: ");
	ft_printf("target a: %d num: %d\n", cost.index_a, cost.num_a);
	ft_printf("target b: %d num: %d\n", cost.index_b, cost.num_b);
	move_both(stack, &cost);
	move_to_top(stack, cost.index_a, 'a');
	move_to_top(stack, cost.index_b, 'b');
	ft_pb(stack, 1);
	if (stack->size_a == 3 || already_sorted(stack, 0, stack->size_a))
	{
		move_to_top(stack, get_bigger_index(stack->b, stack->size_b), 'b');
		return ;
	}
	return (sort_b(stack));
}

static void	push_to_a(t_stack *stack)
{
	int	len;
	int	target;

	len = stack->size_a + stack->size_b - 1;
	while (len >= 0)
	{
		target = get_target(stack);
		if (target == 0)
			ft_rra(stack, 1);
		else
			ft_pa(stack, 1);
		stack->operations_expected++;
		len--;
	}
}

void	large_sort(t_stack *stack)
{
	double_operation(stack, &ft_pb, 2, 1);
	sort_b(stack);
	stack->operations_expected += stack->size_b;
	sort_a(stack);
	show_stack(stack->a, stack->size_a, "Stack A: ");
	show_stack(stack->b, stack->size_b, "Stack B: ");
	push_to_a(stack);
	if (get_smaller_index(stack->a, stack->size_a) != 0)
		move_to_top(stack, get_smaller_index(stack->a, stack->size_a), 'a');
}
