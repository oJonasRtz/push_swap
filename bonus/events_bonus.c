/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:17:23 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/06 15:36:02 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	set_null(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->ocnt = 0;
	stack->operations_expected = 0;
}

void	create_bonus(t_stack *stack, char **argv)
{
	set_null(stack);
	stack_init(&argv[1], stack);
	validate_stack(stack, argv, 0);
	if (!stack->a)
		destroy(stack, NULL);
	execute_bonus(stack);
}

void	execute_bonus(t_stack *stack)
{
	if (read_terminal(stack))
		destroy_bonus(stack, "Error");
	if (already_sorted(stack, 0, stack->size_a) && stack->b == NULL)
		destroy_bonus(stack, "OK");
	destroy_bonus(stack, "KO");
}

void	destroy_bonus(t_stack *stack, char *message)
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
