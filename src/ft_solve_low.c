/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:49:18 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/20 10:29:47 by jopereir         ###   ########.fr       */
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
	bigger_num = get_bigger_num(stack->a, stack->size_a);
	smaller_num = get_smaller_num(stack->a, stack->size_a);
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

	smaller_index = get_smaller_num(stack->a, stack->size_a);
	if (smaller_index != 0)
		move_smaller_to_top(stack, smaller_index, flag);
	ft_pb(stack, flag);
}

void	move_to_top(t_stack *stack, int num, int flag)
{
	int	moves_back;

	if (num != 0)
	{
		if (get_least_moves(stack, num) == num)
			while (num-- > 0)
				ft_ra(stack, flag);
		else
		{
			moves_back = stack->size_a - num;
			while (moves_back-- > 0)
				ft_rra(stack, flag);
		}
	}
}

// static void	solve_stack(t_stack *stack, int *a, int i)
// {
// 	int	smaller;

// 	smaller = get_smaller_num(a, stack->size_a);
// 	if (smaller != 0)
// 	{
// 		if (smaller <= stack->size_a / 2)
// 			while (smaller-- > 0)
// 				ft_ra(stack, 1);
// 		else
// 			while (smaller++ < stack->size_a)
// 				ft_rra(stack, 1);
// 	}
// 	if (i < stack->size_a)
// 		solve_stack(stack, &stack->a[i], i + 1);
// 	return ;
// }

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

	if (stack->size_a  == 2)
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
