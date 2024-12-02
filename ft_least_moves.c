/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_least_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 10:33:38 by jopereir         ###   ########.fr       */
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
		free(temp);
	}
	else if (array_size == 5)
	{
<<<<<<< HEAD
		temp = ft_case5(&a, &b, array_size);
		commands = ft_get_strcat(commands, temp);
		free(temp);
		// free(b);
=======
		// temp = ft_case5(&a, &b, array_size);
		// commands = ft_get_strcat(commands, temp);
		//free(temp);
		b = ft_calloc(array_size, sizeof(int));
		ft_push(&a, &b, array_size);
>>>>>>> 9bc468fd6a7bc7c841fb40afe0979732bfcaeb3d
	}
	if (issorted(a, array_size))
		ft_printf("%s", commands);
	// free(a);
	free(commands);
}
