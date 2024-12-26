/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/26 13:51:35 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_helper_a(t_stack *stack, t_temp_stack *temp, int i)
{
	if (get_index(stack->a, stack->size_a, temp->stack[i]) == 1)
		ft_sa(stack, 1);
	move_to_top(stack, get_index(stack->a, stack->size_a, temp->stack[i]), 'a');
	ft_ra(stack, 1);
	i++;
	if (i >= temp->len)
		return (0);
	return (solve_helper_a(stack, temp, i));
}

// static int	solve_helper_a(t_stack *stack, t_temp_stack *temp, int i)
// {
// 	if (get_index(stack->a, stack->size_a, temp->stack[i]) == 0)
// 	{
// 		ft_ra(stack, 1);
// 		return (i + 1);
// 	}
// 	if (get_index(stack->a, stack->size_a, temp->stack[i]) == 1)
// 	{
// 		ft_sa(stack, 1);
// 		ft_ra(stack, 1);
// 		return (i + 1);
// 	}
// 	else
// 	{
// 		move_to_top(stack, get_index(stack->a, stack->size_a,
// 				temp->stack[i]), 'a');
// 		i++;
// 		if (i >= temp->len || already_sorted2(stack->a, temp, 0, stack->size_a))
// 			return (i);
// 		return (solve_helper_a(stack, temp, i));
// 	}
// }

static int	solve_helper_b(t_stack *stack, t_temp_stack *temp, int i)
{
	if (get_index(stack->b, stack->size_b, temp->stack[i]) == 1)
		ft_sb(stack, 1);
	move_to_top(stack, get_index(stack->b, stack->size_b, temp->stack[i]), 'b');
	ft_pa(stack, 1);
	i++;
	if (i >= temp->len || already_sorted2(stack->b, temp, 0, stack->size_b))
		return (0);
	return (solve_helper_b(stack, temp, i));
}

// static int	solve_helper_b(t_stack *stack, t_temp_stack *temp, int i)
// {
// 	if (get_index(stack->a, stack->size_a, temp->stack[i]) == 0)
// 	{
// 		ft_rb(stack, 1);
// 		return (i + 1);
// 	}
// 	if (get_index(stack->a, stack->size_a, temp->stack[i]) == 1)
// 	{
// 		ft_sb(stack, 1);
// 		ft_rb(stack, 1);
// 		return (i + 1);
// 	}
// 	else
// 	{
// 		move_to_top(stack, get_index(stack->b, stack->size_b,
// 				temp->stack[i]), 'b');
// 		i++;
// 		if (i >= temp->len || already_sorted2(stack->b, temp, 0, stack->size_b))
// 			return (i);
// 		return (solve_helper_b(stack, temp, i));
// 	}
// }

int	solve(t_stack *stack, t_temp_stack *temp_a, t_temp_stack *temp_b)
{
	solve_helper_a(stack, temp_a, 0);
	solve_helper_b(stack, temp_b, 0);
	return (0);
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
