/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:12:46 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/05 15:42:35 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition(t_stack *stack, int pivot, int flag)
{
	int	i;
	int	size_a;

	i = 0;
	size_a = stack->size_a;
	while (i < size_a)
	{
		if (stack->a[0] < pivot)
		{
			ft_pb(stack, flag);
			i++;
		}
		else
			ft_ra(stack, flag);
		size_a = stack->size_a;
	}
}

void	ps_quicksort(t_stack *stack, int flag)
{
	int	pivot;

	if (stack->size_a <= 1)
		return ;
	pivot = stack->a[0];
	partition(stack, pivot, flag);
	ps_quicksort(stack, flag);
	ps_quicksort(stack, flag);
	while (stack->size_b > 0)
		ft_pa(stack, flag);
}
