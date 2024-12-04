/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:49:18 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/03 15:43:32 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Returns the index of the biggest number
*/
int	get_bigger_num(int *n, int array_size)
{
	int	i;
	int	index;

	index = 0;
	i = 1;
	while (i < array_size)
	{
		if (n[i] > n[index])
			index = i;
		i++;
	}
	return (index);
}

int	get_smaller_num(int *n, int array_size)
{
	int	i;
	int	index;

	index = 0;
	i = 1;
	while (i < array_size)
	{
		if (n[i] < n[index])
			index = i;
		i++;
	}
	return (index);
}

char	*get_smallest_to_b(t_stack *stack)
{
	int		smallest;
	int		smallest_index;
	char	*operations;

	operations = ft_calloc(1, 1);
	smallest_index = get_smaller_num(stack->a, stack->size);
	smallest = stack->a[smallest_index];
	while (stack->a[0] != smallest)
	{
		if (smallest_index < stack->size / 2)
			operations = ft_get_strcat(operations, ft_ra(stack));
		else
			operations = ft_get_strcat(operations, ft_rra(stack));
	}
	operations = ft_get_strcat(operations, ft_pb(stack));
	return (operations);
}
