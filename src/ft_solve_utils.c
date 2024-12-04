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

/*
	calls a function 'n' times

	_return is a flag to return the string or not
*/
char	*double_operation(t_stack *stack , char *(*f)(t_stack *), int n, int _return)
{
	int		i;
	char	*operation;

	operation = ft_calloc(1, 1);
	i = 0;
	while (i++ < n)
		operation = ft_get_strcat(operation, f(stack));
	if (_return)
		return (operation);
	else
		return (ft_double_free(operation, NULL));
}

char	*partially_sorted(t_stack *stack)
{
	char	*operations;

	operations = ft_calloc(1, 1);
	double_operation(stack, &ft_pb, 2, 0);
	if (issorted(stack->a, stack->size_a))
	{
		double_operation(stack, &ft_pa, 2, 0);
		operations = ft_get_strcat(operations, ft_sa(stack));
		return (operations);
	}
	double_operation(stack, &ft_pa, 2, 0);
	operations = ft_get_strcat2(operations, double_operation(stack, &ft_rra, 2, 1));
	operations = ft_get_strcat(operations, ft_sa(stack));
	operations = ft_get_strcat2(operations, double_operation(stack, &ft_ra, 2, 1));
	if (issorted(stack->a, stack->size_a))
		return (operations);
	return (ft_double_free(operations, NULL));
}

/*
	1.Push the 2 smalest numbers to stack b
	2.sort stack a with ft_case3
	3.sort stack b to desceding order
	4.push stack b numbers to a
*/
char	*random_sort(t_stack *stack)
{
	char	*operations;

	operations = ft_calloc(1, 1);
	operations = ft_get_strcat2(operations, move_smaller_to_b(stack));
	operations = ft_get_strcat2(operations, move_smaller_to_b(stack));
	operations = ft_get_strcat2(operations, ft_case3(stack));
	operations = ft_get_strcat2(operations, double_operation(stack, &ft_pa, 2, 1));
	return (operations);
}
