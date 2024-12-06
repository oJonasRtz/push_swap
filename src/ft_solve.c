/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:49:18 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/06 12:21:53 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Solves a array of 3 numbers
*/
void	ft_case3(t_stack *stack)
{
	int		bigger_num;
	int		smaller_num;

	if (issorted(stack->a, stack->size_a))
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

/*
	sort stack b in reverse order
	ex:

	1 2
	2 1
*/
// char	*ft_case2_reverse(t_stack *stack)
// {
// 	char	*operations;

// 	operations = ft_calloc(1, 1);
// 	if (stack->b[0] < stack->b[1])
// 		operations = ft_get_strcat(operations, ft_sb(stack));
// 	return (operations);
// }	

void	move_smaller_to_b(t_stack *stack, int flag)
{
	int		smaller_index;

	smaller_index = get_smaller_num(stack->a, stack->size_a);
	if (smaller_index == 0)
		ft_pb(stack, flag);
	else
	{
		move_smaller_to_top(stack, flag);
		ft_pb(stack, flag);
	}
}

void	move_smaller_to_top(t_stack *stack, int flag)
{
	int	smaller;

	smaller = get_smaller_num(stack->a, stack->size_a);
	if (smaller != 0)
	{
		if (smaller <= stack->size_a / 2)
			while (smaller-- > 0)
				ft_ra(stack, flag);
		else
			while (smaller++ < stack->size_a)
				ft_rra(stack, flag);
	}
}

static void	solve_stack(t_stack *stack, int *a, int i)
{
	int	smaller;

	smaller = get_smaller_num(a, stack->size_a);
	if (smaller != 0)
	{
		if (smaller <= stack->size_a / 2)
			while (smaller-- > 0)
				ft_ra(stack, 1);
		else
			while (smaller++ < stack->size_a)
				ft_rra(stack, 1);
	}
	if (i < stack->size_a)
		solve_stack(stack, &stack->a[i], i + 1);
	return ;
}

/*
	1.Push the 2 smalest numbers to stack b
	2.sort stack a with ft_case3
	3.sort stack b to desceding order
	4.push stack b numbers to a
*/
void	random_sort(t_stack *stack)
{
	int			half;

	if (partially_sorted(stack))
		return ;
	half = stack->size_a / 2;
	double_operation(stack, &move_smaller_to_b, half, 1);
	if (stack->size_a == 3)
		ft_case3(stack);
	else
		solve_stack(stack, stack->a, 0);
	double_operation(stack, &ft_pa, half, 1);
}
