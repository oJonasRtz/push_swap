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
	Solves a array of 3 numbers
*/
char	*ft_case3(t_stack *stack)
{
	char	*operations;
	int		bigger_num;
	int		smaller_num;

	if (issorted(stack->a, stack->size_a))
		return (NULL);
	operations = ft_calloc (1, 1);
	bigger_num = get_bigger_num(stack->a, stack->size_a);
	smaller_num = get_smaller_num(stack->a, stack->size_a);
	if (bigger_num == stack->size_a - 1)
		operations = ft_get_strcat(operations, ft_sa(stack));
	else if (bigger_num == 0 && smaller_num == stack->size_a - 1)
	{
			operations = ft_get_strcat(operations, ft_sa(stack));
			operations = ft_get_strcat(operations, ft_rra(stack));
	}
	else if (bigger_num == 0 && smaller_num != stack->size_a - 1)
			operations = ft_get_strcat(operations, ft_ra(stack));
	else if (smaller_num == 0)
	{
		operations = ft_get_strcat(operations, ft_sa(stack));
		operations = ft_get_strcat(operations, ft_ra(stack));
	}
	else
		operations = ft_get_strcat(operations, ft_rra(stack));
	return (operations);
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

char	*move_smaller_to_b(t_stack *stack)
{
	int		smaller_index;
	char	*operations;

	operations = ft_calloc(1, 1);
	smaller_index = get_smaller_num(stack->a, stack->size_a);
	if (smaller_index == 0)
		operations = ft_get_strcat(operations, ft_pb(stack));
	else if (smaller_index <= stack->size_a / 2)
	{
		while (smaller_index-- > 0)
			operations = ft_get_strcat(operations, ft_ra(stack));
		operations = ft_get_strcat(operations, ft_pb(stack));
	}
	else
	{
		while (smaller_index++ < stack->size_a)
			operations = ft_get_strcat(operations, ft_rra(stack));
		operations = ft_get_strcat(operations, ft_pb(stack));
	}
	return (operations);
}

/*
	1.push the two smallest numbers to stack b
	2.aplly case 3 to stack a
	3.sort stack b in reverse order
	4.push the two numbers from stack b to stack a
*/
char	*ft_case5(t_stack *stack)
{
	char	*operations;
	char	*partially_sorted_operations;

	operations = ft_calloc(1, 1);
	partially_sorted_operations = partially_sorted(stack);
	if (partially_sorted_operations)
		operations = ft_get_strcat2(operations, partially_sorted_operations);
	else
		operations = ft_get_strcat2(operations, random_sort(stack));
	return (operations);
}
