/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:53:59 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/06 15:34:50 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Initiate the stacks with 0/NULL values
static void	set_null(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->ocnt = 0;
	stack->operations_expected = 0;
}

/*
	Init values
	Validate the values
		Quality requisit
*/
int	create(char **argv, t_stack *stack)
{
	set_null(stack);
	stack_init(&argv[1], stack);
	validate_stack(stack, argv, 1);
	if (!stack->a)
		destroy(stack, NULL);
	execute(stack);
	return (1);
}

/*
	Execute the program
		Functional requisit
*/
int	execute(t_stack *stack)
{
	if (stack->size_a <= 7)
		tiny_sort(stack);
	else
		large_sort(stack);
	destroy(stack, NULL);
	return (1);
}

/*
	free every alloc memmory
*/
int	destroy(t_stack *stack, char *message)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	set_null(stack);
	if (message)
		ft_printf("%s\n", message);
	exit(0);
}
