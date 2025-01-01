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

static int  check_a(t_stack *stack, int num)
{
	int cost;
	int i;

	cost = 0;
	if (num == stack->a[0])
		return (cost);
	i = 0;
	while (stack->a[i] != num)
		i++;
	cost = get_least_moves(stack->size_a, i);
	return (cost);
}

static int  check_b(t_stack *stack, int num)
{
	int i;
	int j;

	if (num > max(stack->b, stack->size_b)
		|| num < min(stack->b, stack->size_b))
		return (get_least_moves(stack->size_b, get_bigger_index(stack->b, stack->size_b)));
	i = 0;
	while (stack->b[i] > num)
		i++;
	j = stack->size_b - 1;
	while (stack->b[j] < num)
		j--;
	if (get_least_moves(stack->size_b, j) < get_least_moves(stack->size_b, i))
		return (get_least_moves(stack->size_b, j));
	return (get_least_moves(stack->size_b, i));
}

void	check_best_push(t_stack *stack)
{
	int cost;
	int index;
	int i;

	i = 0;
	cost = INT_MAX;
	index = 0;
	while (i < stack->size_a)
	{
		if (check_a(stack, stack->a[i]) + check_b(stack, stack->a[i]) + 1 < cost)
		{
			cost = check_a(stack, stack->a[i]) + check_b(stack, stack->a[i]) + 1;
			index = i;
		}
		i++;
	}
	if (index != 0)
		move_to_top(stack, index, 'a');
}
