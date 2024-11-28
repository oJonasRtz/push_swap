/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:25:28 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 15:54:28 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_init(char **s, int *size)
{
	int	*stack;
	int	i;
	int	j;

	i = 1;
	while (s[i])
		i++;
	*size = i - 1;
	stack = ft_calloc(i, sizeof(int));
	if (!stack)
		return (NULL);
	i = 1;
	j = 0;
	while (s[i])
		stack[j++] = ft_atoi(s[i++]);
	return (stack);
}
