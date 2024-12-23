/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:11:30 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/23 15:25:40 by jopereir         ###   ########.fr       */
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
	int	*temp;
	int	i;

	temp = ft_calloc(stack->size_a, sizeof(int));
	if (!temp)
		destroy(stack, NULL);
	cpy_stack(temp, stack->a, stack->size_a);
	ft_quicksort(temp, 0, stack->size_a - 1);
	i = first;
	while (i < last)
	{
		if (temp[i] != stack->a[i])
		{
			free(temp);
			return (0);
		}
		i++;
	}
	free(temp);
	return (1);
}

int	already_sorted2(int *stack, t_temp_stack *temp, int first, int last)
{
	int	i;

	i = first;
	while (i < last)
	{
		if (temp->stack[i] != stack[i])
			return (0);
		i++;
	}
	return (1);
}
