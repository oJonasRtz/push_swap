/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_least_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 14:15:00 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_strcat(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (!s)
		return (NULL);
	free(s1);
	return (s);
}

/*
	condition && (a || b) is useless, I just did it to silence Werror
*/
void	ft_least_moves(t_stack *stack)
{
	char	*commands;
	char	*temp;

	commands = ft_calloc(1, 1);
	temp = NULL;
	if (stack->size == 2)
		commands = ft_get_strcat(commands, ft_sa(stack));
	else if (stack->size == 3)
	{
		temp = ft_case3(stack);
		commands = ft_get_strcat(commands, temp);
		free(temp);
	}
	else if (stack->size == 5)
	{
		temp = ft_case5(stack);
		commands = temp;
		ft_double_free(temp, stack->b);
	}
	if (issorted(stack->a, stack->size))
		ft_printf("%s", commands);
	free(commands);
}
