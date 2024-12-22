/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/20 10:38:59 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(int *stack, int size)
{
	int	*temp;
	int	pi;

	temp = ft_calloc(size, sizeof(int));
	cpy_stack(temp, stack, size);
	ft_quicksort(temp, 0, size);
	pi = temp[size / 2];
	free(temp);
	return (pi);
}

void    large_sort(t_stack *stack)
{
	int	pivot;
	int	len;

	pivot = get_pivot(stack->a, stack->size_a);
	len = stack->size_a;
	while (len != stack->size_a / 2 + stack->size_a % 2)
	{
		if (stack->a[0] < pivot && len--)
			ft_pb(stack, 1);
		else
			ft_ra(stack, 1);
	}
	
}
