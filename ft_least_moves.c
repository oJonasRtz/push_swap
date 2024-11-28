/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_least_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 12:46:49 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_strcat(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	free(s1);
	return (s);
}

/*
	condition && (a || b) is useless, I just did it to silence Werror
*/
void	ft_least_moves(int *a, int *b, int array_size)
{
	char	*commands;
	char	*temp;

	commands = ft_calloc(1, 1);
	temp = NULL;
	if (array_size == 2 && (a || b))
		commands = ft_get_strcat(commands, ft_sa(a, array_size));
	else if (array_size == 3)
	{
		temp = ft_case3(&a, array_size);
		commands = ft_get_strcat(commands, temp);
	}
	if (issorted(a, array_size))
		ft_printf("%s", commands);
	free(temp);
	free(commands);
}
