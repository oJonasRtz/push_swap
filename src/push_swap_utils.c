/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:02:13 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/12 11:18:54 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isalldigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && (s[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

/*
	The comparisons work like as in insertion sort
*/
static int	isduplicate(char *s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = i - 1;
		while (j >= 0)
		{
			if (s[j] == s[i])
				return (1);
			j--;
		}
		i++;
	}
	return (0);
}

static int	islargerthan_limits(char *s, t_stack *stack)
{
	int		i;
	char	**temp;

	temp = ft_split(s, ' ');
	i = 0;
	while (temp[i])
	{
		if ((stack->a[i] == INT_MAX && ft_strncmp(temp[i], "2147483647", 11) != 0)
			|| (stack->a[i] == INT_MIN && ft_strncmp(temp[i], "-2147483648", 12) != 0))
		{
			free_split(temp);
			return (1);
		}
		i++;
	}
	free_split(temp);
	return (0);
}

int	validate_stack(t_stack *stack, char *argv)
{
	if (already_sorted(stack))
		program_destroy(stack, NULL);
	if (!isalldigit(argv) || isduplicate(argv) || islargerthan_limits(argv, stack))
		program_destroy(stack, "Error: stack is not valid.");
	return (1);
}
