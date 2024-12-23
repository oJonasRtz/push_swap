/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/23 13:57:59 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve(t_stack *stack, int *temp_a, int *temp_b)
{
	if (!already_sorted2(stack->a, stack->size_a, 0, stack->size_a - 1))
	{
		//solve a
	}
	if (!already_sorted2(stack->b, stack->size_b, 0, stack->size_b - 1))
	{
		//solve b
	}
	return (1);
}

/*
    find the first index of a value of temp in stack a
*/
int	get_first(t_stack *stack, int *temp, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = 0;
		while (j < len)
		{
			if (stack->a[i] == temp[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	get_last(t_stack *stack, int *temp, int len)
{
	int	i;
	int	j;

	i = stack->size_a - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < len)
		{
			if (stack->a[i] == temp[j])
				return (i);
			j++;
		}
		i--;
	}
	return (-1);
}

int	get_least_moves(t_stack *stack, int index)
{
	if (stack->size_a - index < index)
		return (stack->size_a - index);
	return (index);
}
