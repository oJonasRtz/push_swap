/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:32:23 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 14:13:59 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_ra(t_stack *stack)
{
	ft_rotate(&stack->a, stack->size);
	return ("ra\n");
}

char	*ft_pb(t_stack *stack)
{
	ft_push(&stack->a, &stack->b, stack->size);
	return ("pb\n");
}

char	*ft_pa(t_stack *stack)
{
	ft_push(&stack->b, &stack->a, stack->size);
	return ("pa\n");
}
