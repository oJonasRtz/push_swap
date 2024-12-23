/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:25:28 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/19 15:39:30 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(char **s, t_stack *stack)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	stack->size_a = i;
	stack->a = ft_calloc(i, sizeof(int));
	i = 0;
	while (s[i])
	{
		stack->a[i] = ft_atoi(s[i]);
		i++;
	}
}
