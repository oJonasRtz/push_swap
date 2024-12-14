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

void    ft_rb(t_stack *stack, int flag)
{
    ft_rotate(&stack->b, stack->size_b);
    if (flag)
    {
        stack->ocnt++;
        ft_printf("rb\n");
    }
}
