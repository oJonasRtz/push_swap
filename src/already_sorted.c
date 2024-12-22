/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:11:30 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/20 10:28:38 by jopereir         ###   ########.fr       */
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
		destroy(stack, "Error: already_sorted failed");
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
