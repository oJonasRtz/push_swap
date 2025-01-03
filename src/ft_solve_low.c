/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_low.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:49:18 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 10:35:05 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Solves a array of 3 numbers
*/
static void	ft_case3(t_stack *stack)
{
	int		bigger_num;
	int		smaller_num;

	if (already_sorted(stack, 0, stack->size_a))
		return ;
	bigger_num = get_bigger_index(stack->a, stack->size_a);
	smaller_num = get_smaller_index(stack->a, stack->size_a);
	if (bigger_num == stack->size_a - 1)
		ft_sa(stack, 1);
	else if (bigger_num == 0 && smaller_num == stack->size_a - 1)
	{
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	else if (bigger_num == 0 && smaller_num != stack->size_a - 1)
		ft_ra(stack, 1);
	else if (smaller_num == 0)
	{
		ft_sa(stack, 1);
		ft_ra(stack, 1);
	}
	else
		ft_rra(stack, 1);
}

void	move_smaller_to_b(t_stack *stack, int flag)
{
	int		smaller_index;

	smaller_index = get_smaller_index(stack->a, stack->size_a);
	if (smaller_index != 0)
		move_to_top(stack, smaller_index, 'a');
	ft_pb(stack, flag);
}

/*
	1.Push the 2 smalest numbers to stack b
	2.sort stack a with ft_case3
	3.sort stack b to desceding order
	4.push stack b numbers to a
*/
static void	ft_case5(t_stack *stack)
{
	int			half;

	if (partially_sorted(stack))
		return ;
	half = stack->size_a - 3;
	double_operation(stack, &move_smaller_to_b, half, 1);
	ft_case3(stack);
	double_operation(stack, &ft_pa, half, 1);
}

void	tiny_sort(t_stack *stack)
{
	int	case7;

	if (stack->size_a == 2)
		ft_sa(stack, 1);
	else if (stack->size_a == 3)
		ft_case3(stack);
	else if (stack->size_a <= 5)
		ft_case5(stack);
	else if (stack->size_a <= 7)
	{
		if (partially_sorted(stack))
			return ;
		case7 = stack->size_a - 5;
		double_operation(stack, &move_smaller_to_b, case7, 1);
		ft_case5(stack);
		double_operation(stack, &ft_pa, case7, 1);
	}
}
