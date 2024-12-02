/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:55:19 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 14:13:26 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_ss(t_stack *stack)
{
	ft_swap(&stack->a, stack->size);
	ft_swap(&stack->b, stack->size);
	return ("ss\n");
}

char	*ft_rr(t_stack *stack)
{
	ft_rotate(&stack->a, stack->size);
	ft_rotate(&stack->b, stack->size);
	return ("rr\n");
}

char	*ft_rrr(t_stack *stack)
{
	ft_reverse_rotate(&stack->a, stack->size);
	ft_reverse_rotate(&stack->b, stack->size);
	return ("rrr\n");
}

char	*ft_sa(t_stack *stack)
{
	ft_swap(&stack->a, stack->size);
	return ("sa\n");
}

char	*ft_rra(t_stack *stack)
{
	ft_reverse_rotate(&stack->a, stack->size);
	return ("rra\n");
}
