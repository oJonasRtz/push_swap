/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/26 16:05:46 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_least_moves(int size, int index)
{
	if (size - index < index)
		return (size - index);
	return (index);
}

static int	cpy_stack2(int *dest, int *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	return (i);
}

static void	init_temp(t_temp_stack *temp_a,
	t_temp_stack *temp_b, t_stack *stack)
{
	int	*temp;

	temp = ft_calloc(stack->size_a, sizeof(int));
	cpy_stack(temp, stack->a, stack->size_a);
	ft_quicksort(temp, 0, stack->size_a - 1);
	temp_b->len = cpy_stack2(temp_b->stack, temp, 0, stack->size_a / 2);
	temp_a->len = cpy_stack2(temp_a->stack, temp,
			stack->size_a / 2 + (stack->size_a % 2 != 0), stack->size_a);
	reverse_quicksort(temp_b->stack, 0, temp_b->len - 1);
	free(temp);
}

static void	move_to_b(t_stack *stack, int *temp_b, int len)
{
	int	first;
	int	last;
	int	min_dist;

	first = get_first(stack, temp_b, len);
	last = get_last(stack, temp_b, len);
	min_dist = first;
	if (min_dist == 0)
		return (ft_pb(stack, 1));
	if (get_least_moves(stack->size_a, last) < first)
		min_dist = last;
	move_to_top(stack, min_dist, 'a');
	ft_pb(stack, 1);
}

void	large_sort(t_stack *stack)
{
	t_temp_stack	temp_a;
	t_temp_stack	temp_b;
	int				i;
	int				op;

	temp_b.stack = ft_calloc(stack->size_a / 2, sizeof(int));
	temp_a.stack = ft_calloc(stack->size_a / 2
			+ (stack->size_a % 2 != 0), sizeof(int));
	init_temp(&temp_a, &temp_b, stack);
	op = temp_b.len;
	i = 0;
	while (i < temp_b.len)
	{
		move_to_b(stack, temp_b.stack, op);
		i++;
	}
	solve(stack, &temp_a, &temp_b, 0);
	double_operation(stack, &ft_pa, op, 1);
	ft_double_free(temp_a.stack, temp_b.stack);
}
