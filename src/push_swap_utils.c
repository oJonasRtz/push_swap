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
	int	i;
	int	num;

	i = 0;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		if ((num == INT_MAX && ft_strncmp(s[i], "2147483647", 11) != 0)
			|| (num == INT_MIN && ft_strncmp(s[i], "-2147483648", 12) != 0))
			return (1);
		i++;
	}
	return (0);
}
