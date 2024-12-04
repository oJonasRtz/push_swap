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

	operations = ft_calloc (1, 1);
	bigger_num = get_bigger_num(stack->a, stack->size);
	smaller_num = get_smaller_num(stack->a, stack->size);
	if (bigger_num == stack->size - 1)
		operations = ft_get_strcat(operations, ft_sa(stack));
	else if (bigger_num == 0 && smaller_num == stack->size - 1)
	{
			operations = ft_get_strcat(operations, ft_sa(stack));
			operations = ft_get_strcat(operations, ft_rra(stack));
	}
	else if (bigger_num == 0 && smaller_num != stack->size - 1)
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
char	*ft_case2_reverse(t_stack *stack)
{
	char	*operations;

	operations = ft_calloc(1, 1);
	if (stack->b[0] < stack->b[1])
		operations = ft_get_strcat(operations, ft_sb(stack));
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

	if (!stack->b)
		stack->b = ft_calloc(stack->size + 1, sizeof(int));
	operations = ft_calloc(1, 1);

	operations = ft_get_strcat2(operations, get_smallest_to_b(stack));
	operations = ft_get_strcat2(operations, get_smallest_to_b(stack));

	operations = ft_get_strcat2(operations, ft_case3(stack));

	operations = ft_get_strcat2(operations, ft_case2_reverse(stack));
	
	operations = ft_get_strcat2(operations, ft_pa(stack));
	operations = ft_get_strcat2(operations, ft_pa(stack));
	return (operations);
}
