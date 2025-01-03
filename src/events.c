/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:53:59 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 10:46:36 by jopereir         ###   ########.fr       */
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

//	temp function
void	show_stack(int *stack, int size, char *text)
{
	int	i;

	i = 0;
	ft_printf("%s", text);
	while (i < size)
		ft_printf("%d ", stack[i++]);
	ft_printf("\n");
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
	validate_stack(stack, argv);
	if (!stack->a)
		destroy(stack, "Error: stack_init failed");
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
	//Essas duas linhas devem ser apagadas antes de enviar o projeto pra avaliação
	show_stack(stack->a, stack->size_a, "Stack A:");
	show_stack(stack->b, stack->size_b, "Stack B:");
	ft_printf("Size_a: %d Operations: %d\n", stack->size_a, stack->ocnt);
	ft_printf("Operations expected: %d\n", stack->operations_expected);
	ft_printf("Sorted: %d\n", already_sorted(stack, 0, stack->size_a));
	
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
