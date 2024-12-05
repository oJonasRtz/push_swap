/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:32:23 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/05 12:07:25 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack, int flag)
{
	ft_rotate(&stack->a, stack->size_a);
	if (flag)
		ft_printf("ra\n");
}

void	ft_pb(t_stack *stack, int flag)
{
	ft_push(&stack->a, &stack->b, &stack->size_a, &stack->size_b);
	if (flag)
		ft_printf("pb\n");
}

void	ft_pa(t_stack *stack, int flag)
{
	ft_push(&stack->b, &stack->a, &stack->size_b, &stack->size_a);
	if (flag)
		ft_printf("pa\n");
}

void	ft_rra(t_stack *stack, int flag)
{
	ft_reverse_rotate(&stack->a, stack->size_a);
	if (flag)
		ft_printf("rra\n");
}
