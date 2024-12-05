/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_least_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/05 13:23:23 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	condition && (a || b) is useless, I just did it to silence Werror
*/
void	ft_least_moves(t_stack *stack)
{
	if (stack->size_a == 2)
		ft_sa(stack, 1);
	else if (stack->size_a == 3)
		ft_case3(stack);
	else
		random_sort(stack);
}
