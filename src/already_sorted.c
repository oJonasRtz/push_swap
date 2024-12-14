/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:11:30 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 10:10:21 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cpy_stack(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	already_sorted(t_stack *stack)
{
	int	*temp;
	int	i;

	temp = ft_calloc(stack->size_a, sizeof(int));
	if (!temp)
		program_destroy(stack, "Error: already_sorted failed");
	cpy_stack(temp, stack->a, stack->size_a);
	ft_quicksort(temp, 0, stack->size_a - 1);
	i = 0;
	while (i < stack->size_a)
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

int	issorted(int *n, int array_size)
{
	int	i;

	if (!n)
		return (0);
	i = 1;
	while (i < array_size)
	{
		if (n[i] < n[i - 1])
			return (0);
		i++;
	}
	return (1);
}
