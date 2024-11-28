/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:02:13 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 14:16:32 by jopereir         ###   ########.fr       */
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

	stack = ft_calloc((array_size - 1), sizeof(int));
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

	stack = ft_calloc(array_size, sizeof(int));
	if (!stack)
		return (NULL);
	i = 0;
	j = 1;
	while (i < array_size)
		stack[j++] = n[i++];
	free(n);
	return (stack);
}

int	isalldigit(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '-')
			j++;
		while (s[i][j])
		{
			if (!ft_isdigit(s[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
	The comparisons work like as in insertion sort
*/
int	isduplicate(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = i - 1;
		while (j >= 0)
		{
			if (ft_strncmp(s[i], s[j], ft_strlen(s[i])) == 0)
				return (1);
			j--;
		}
		i++;
	}
	return (0);
}

int	islargerthan_limits(char **s)
{
	int		i;
	long	num;

	i = 0;
	while (s[i])
	{
		num = (long)ft_atoi(s[i]);
		if ((num == INT_MAX && ft_strncmp(s[i], "2147483647", 11) != 0)
			|| (num == INT_MIN && ft_strncmp(s[i], "-2147483648", 12) != 0))
			return (1);
		i++;
	}
	return (0);
}
