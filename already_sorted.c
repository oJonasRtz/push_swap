/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:11:30 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 10:10:21 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(char **s)
{
	int	i;
	int	num;
	int	num2;

	i = 1;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		num2 = ft_atoi(s[i - 1]);
		if (num <= num2)
			return (0);
		i++;
	}
	return (1);
}

int	issorted(int *n, int array_size)
{
	int	i;

	if (!n)
		return (0);
	i = 1;
	while (i < array_size)
	{
		if (n[i] < n[i - 1])
			return (0);
		i++;
	}
	return (1);
}
