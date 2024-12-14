/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:53:59 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/13 11:55:49 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_null(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->ocnt = 0;
}

// static void	show_stack(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("Stack A: ");
// 	while (i < stack->size_a)
// 		ft_printf("%d ", stack->a[i++]);
// 	ft_printf("\n");
// }

int	program_create(char **argv, t_stack *stack)
{
	set_null(stack);
	stack_init(&argv[1], stack);
	if (!stack->a)
		program_destroy(stack, "Error: stack_init failed");
	if (!validate_stack(stack, &argv[1]))
		program_destroy(stack, "Error: validate_stack failed");
	program_execute(stack);
	return (1);
}

int	program_execute(t_stack *stack)
{
	if (stack->size_a == 2)
		ft_sa(stack, 1);
	else if (stack->size_a == 3)
		ft_case3(stack);
	else if (stack->size_a == 5)
		ft_case5(stack);
	
	//Essas duas linhas devem ser apagadas antes de enviar o projeto pra avaliação
	// show_stack(stack);
	// ft_printf("Size_a: %d Operations: %d\n", stack->size_a, stack->ocnt);

	program_destroy(stack, NULL);
	return (1);
}

int	program_destroy(t_stack *stack, char *message)
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
