/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:02:13 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/25 10:02:12 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	get the amount of index of an array
*/
int	ft_arraylen(int *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	*arrayup(int *n)
{
	int	*stack;
	int	i;
	int	j;

	stack = malloc((ft_arraylen(n) - 1) * sizeof(int));
	if (!stack)
		return (NULL);
	i = 1;
	j = 0;
	while (n[i])
		stack[j++] = n[i++];
	return (stack);
}

int	*arraydown(int *n)
{
	int	*stack;
	int	i;
	int	j;

	stack = malloc((ft_arraylen(n) + 1) * sizeof(int));
	if (!stack)
		return (NULL);
	i = 0;
	j = 1;
	while (n[i])
		stack[j++] = n[i++];
	return (stack);
}

void	ft_double_free(int *a, int *b)
{
	free(a);
	free(b);
}
