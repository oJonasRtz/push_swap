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
	ft_swap(&stack->a, stack->size_a);
	ft_swap(&stack->b, stack->size_b);
	return ("ss\n");
}

char	*ft_rr(t_stack *stack)
{
	ft_rotate(&stack->a, stack->size_a);
	ft_rotate(&stack->b, stack->size_b);
	return ("rr\n");
}

char	*ft_rrr(t_stack *stack)
{
	ft_reverse_rotate(&stack->a, stack->size_a);
	ft_reverse_rotate(&stack->b, stack->size_b);
	return ("rrr\n");
}

char	*ft_sa(t_stack *stack)
{
	ft_swap(&stack->a, stack->size_a);
	return ("sa\n");
}

char	*ft_sb(t_stack *stack)
{
	ft_swap(&stack->b, stack->size_b);
	return ("sb\n");
}	

char	*ft_rra(t_stack *stack)
{
	ft_reverse_rotate(&stack->a, stack->size_a);
	return ("rra\n");
}
