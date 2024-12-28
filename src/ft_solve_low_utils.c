/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_low_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:49:18 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/28 12:15:51 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int *stack, int n)
{
	int	i;

	i = 0;
	while (stack[i] != n)
		i++;
	return (i);
}

/*
	Returns the index of the biggest number
*/
int	get_bigger_index(int *n, int array_size)
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

int	get_smaller_index(int *n, int array_size)
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

/*
	calls a function 'n' times

	_return is a flag to return the string or not
*/
void	double_operation(t_stack *stack,
		void (*f)(t_stack *, int), int n, int flag)
{
	int		i;

	i = 0;
	while (i++ < n)
		f(stack, flag);
}

int	partially_sorted(t_stack *stack)
{
	if (already_sorted(stack, 2, stack->size_a))
		ft_sa(stack, 1);
	if (already_sorted(stack, 0, stack->size_a - 2))
	{
		double_operation(stack, &ft_rra, 2, 1);
		ft_sa(stack, 1);
		double_operation(stack, &ft_ra, 2, 1);
	}
	else if (already_sorted(stack, 1, stack->size_a - 1))
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
		ft_ra(stack, 1);
	}
	if (already_sorted(stack, 0, stack->size_a))
		return (1);
	return (0);
}

/*
	return 0 if it was sorted
		0 if it doesn't
*/
// int	partially_sorted(t_stack *stack)
// {
// 	double_operation(stack, &ft_pb, 2, 0);
// 	if (already_sorted(stack, 0, stack->size_a))
// 	{
// 		double_operation(stack, &ft_pa, 2, 0);
// 		ft_sa(stack, 1);
// 		return (1);
// 	}
// 	double_operation(stack, &ft_pa, 2, 0);
// 	double_operation(stack, &ft_rra, 2, 0);
// 	ft_sa(stack, 0);
// 	double_operation(stack, &ft_ra, 2, 0);
// 	if (already_sorted(stack, 0, stack->size_a))
// 		ft_printf("rra\nrra\nsa\nra\nra\n");
// 	else
// 	{
// 		double_operation(stack, &ft_rra, 2, 0);
// 		ft_sa(stack, 0);
// 		double_operation(stack, &ft_ra, 2, 0);
// 		ft_rra(stack, 1);
// 		ft_sa(stack, 1);
// 		ft_ra(stack, 1);
// 	}
// 	if (already_sorted(stack, 0, stack->size_a))
// 		return (1);
// 	return (0);
// }
