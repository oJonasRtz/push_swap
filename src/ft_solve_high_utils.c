/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/23 15:40:26 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_helper_a(t_stack *stack, t_temp_stack *temp, int i)
{
	if (already_sorted2(stack->a, temp, 0, stack->size_a - 1))
		return (1);
	if (temp->stack[temp->len - 1 + i] == stack->a[0])
	{
		if (temp->stack[temp->len - 2 + i] == stack->a[1])
		{
			ft_sa(stack, 1);
			ft_rra(stack, 1);
			ft_rra(stack, 1);
			i++;
			return (1);
		}
	}
	else
	{
		ft_rra(stack, 1);
		solve_helper_a(stack, temp, i);
		ft_sa(stack, 1);
	}
	return (0);
}

static int	solve_helper_b(t_stack *stack, t_temp_stack *temp, int i)
{
	if (already_sorted2(stack->b, temp, 0, stack->size_b - 1))
		return (1);
	if (temp->stack[temp->len - 1 + i] == stack->b[0])
	{
		if (temp->stack[temp->len - 2 + i] == stack->b[1])
		{
			ft_sb(stack, 1);
			ft_rrb(stack, 1);
			ft_rrb(stack, 1);
			i++;
			return (1);
		}
	}
	else
	{
		ft_rrb(stack, 1);
		solve_helper_b(stack, temp, i);
		ft_sb(stack, 1);
	}
	return (0);
}

int	solve(t_stack *stack, t_temp_stack *temp_a, t_temp_stack *temp_b)
{
	int	i;

	i = 0;
	if (!solve_helper_a(stack, temp_a, i))
		return (0);
	i = 0;
	if (!solve_helper_b(stack, temp_b, i))
		return (0);
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
