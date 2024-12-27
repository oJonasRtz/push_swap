/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:11:30 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/27 15:15:36 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy_stack(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

/*
	Verifies up to 'n' if a stack is already sorted
*/
int	already_sorted(t_stack *stack, int first, int last)
{
	int	i;

	stack->sorted = ft_calloc(stack->size_a, sizeof(int));
	if (!stack->sorted)
		destroy(stack, NULL);
	cpy_stack(stack->sorted, stack->a, stack->size_a);
	ft_quicksort(stack->sorted, 0, stack->size_a - 1);
	i = first;
	while (i < last)
	{
		if (stack->sorted[i] != stack->a[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (stack[i] < stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}
