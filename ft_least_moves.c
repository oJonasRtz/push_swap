/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_least_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 10:13:22 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strcat(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	free(s1);
	return (s);
}

/*
	condition && (a || b) is useless, I just did it to silence Werror
*/
void	ft_least_moves(int *a, int *b, int size)
{
	char	*commands;

	commands = ft_calloc(11, 1);
	if (size == 2 && (a || b))
		commands = ft_strcat(commands, "sa");
	else
		ft_strlcpy(commands, "std_output", 11);
	ft_printf("%s\n", commands);
	free(commands);
}
