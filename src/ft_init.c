/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:25:28 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/06 12:47:51 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*stack_init(char *s, int *size)
// {
// 	int	*stack;
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (s[i])
// 		i++;
// 	*size = i - 1;
// 	stack = ft_calloc(i, sizeof(int));
// 	if (!stack)
// 		return (NULL);
// 	i = 1;
// 	j = 0;
// 	while (s[i])
// 		stack[j++] = ft_atoi(s[i++]);
// 	return (stack);
// }

int	*stack_init(char *s, int *size)
{
	int		*stack;
	char	**split;
	int		i;

	split = ft_split(s, ' ');
	i = 0;
	while (split[i])
		i++;
	*size = i;
	stack = ft_calloc(i, sizeof(int));
	i = 0;
	while (split[i])
	{
		stack[i] = ft_atoi(split[i]);
		i++;
	}
	return (stack);
}
