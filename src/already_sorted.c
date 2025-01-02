/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:11:30 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/02 14:59:11 by jopereir         ###   ########.fr       */
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

	i = first + 1;
	while (i < last && i < stack->size_a)
	{
		if (stack->a[i] < stack->a[i - 1])
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
