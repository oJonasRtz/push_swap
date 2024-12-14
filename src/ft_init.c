/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:25:28 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/06 12:59:23 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	stack_init(char **s, t_stack *stack)
{
	int	i;

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

// void	stack_init(char *s, t_stack *stack)
// {
// 	char	**split;
// 	int		i;

// 	split = ft_split(s, ' ');
// 	if (!split)
// 		return ;
// 	i = 0;
// 	while (split[i])
// 		i++;
// 	stack->size_a = i;
// 	stack->a = ft_calloc(i, sizeof(int));
// 	if (!stack->a)
// 	{
// 		free_split(split);
// 		return ;
// 	}
// 	i = 0;
// 	while (split[i])
// 	{
// 		stack->a[i] = ft_atoi(split[i]);
// 		i++;
// 	}
// 	free_split(split);
// }
