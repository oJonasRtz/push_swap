/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/23 10:29:40 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cpy_stack2(int *dest, int *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
}

static void	init_temp(int *temp_a, int *temp_b, t_stack *stack)
{
	int	*temp;

	temp = ft_calloc(stack->size_a, sizeof(int));
	cpy_stack(temp, stack->a, stack->size_a);
	ft_quicksort(temp, 0, stack->size_a);
	cpy_stack(temp_b, temp, stack->size_a / 2);
	cpy_stack2(temp_a, temp, stack->size_a / 2 + 1, stack->size_a);
	free(temp);
}

// static int	check_sort(int *stack, int size, int *sorted)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (stack[i] != sorted[i])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

static void	move_to_b(t_stack *stack, int *temp_b)
{
	int	first;
	int	last;
	int	min_dist;

	first = get_first(stack, temp_b);
	last = get_last(stack, temp_b);
	min_dist = first;
	if (min_dist == 0)
		return (ft_pb(stack, 1));
	if (get_least_moves(stack, last) < first)
		min_dist = last;
	move_to_top(stack, min_dist, 1);
	ft_pb(stack, 1);
}

void	large_sort(t_stack *stack)
{
	int	*temp_a;
	int	*temp_b;
	int	i;

	temp_a = ft_calloc(stack->size_a / 2 + stack->size_a % 2, sizeof(int));
	temp_b = ft_calloc(stack->size_a / 2, sizeof(int));
	init_temp(temp_a, temp_b, stack);
	i = 0;
	while (i < stack->size_a / 2)
	{
		move_to_b(stack, temp_b);
		i++;
	}
}
