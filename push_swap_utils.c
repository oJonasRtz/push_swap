/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:02:13 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/27 10:44:21 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Removes the first element of the array
*/
int	*arrayup(int *n, int array_size)
{
	int	*stack;
	int	i;
	int	j;

	stack = malloc((array_size - 1) * sizeof(int));
	if (!stack)
		return (NULL);
	i = 1;
	j = 0;
	while (i < array_size)
		stack[j++] = n[i++];
	free(n);
	return (stack);
}

/*
	free the first slot of the array pushing the other numbers

	1, 2, 3
	0, 1, 2, 3
	the fisrt slot isn't filled
*/
int	*arraydown(int *n, int array_size)
{
	int	*stack;
	int	i;
	int	j;

	stack = malloc(array_size * sizeof(int));
	if (!stack)
		return (NULL);
	i = 0;
	j = 1;
	while (i < array_size)
		stack[j++] = n[i++];
	free(n);
	return (stack);
}

void	ft_double_free(int *a, int *b)
{
	free(a);
	free(b);
}
