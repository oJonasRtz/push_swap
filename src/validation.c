/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:02:13 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/20 10:16:56 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isalldigit(char **s)
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
			{
				ft_printf("digit\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
	The comparisons work like as in insertion sort
*/
static int	isduplicate(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i - 1;
		while (j >= 0)
		{
			if (ft_strncmp(s[i], s[j], ft_strlen(s[i])) == 0)
				return (ft_printf("Duplicate\n"));
			j--;
		}
		i++;
	}
	return (0);
}

/*
	ft_atoi returns the INT_MAX if the values pass it, so the function
		must verify if the string and the value are equals
*/
static int	islargerthan_limits(char **s, t_stack *stack)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (is_larger_than_int_max(stack->a[i], s[i])
			|| is_less_than_int_min(stack->a[i], s[i]))
			return (ft_printf("Larger\n"));
		i++;
	}
	return (0);
}

int	validate_stack(t_stack *stack, char **argv)
{
	if (already_sorted(stack, stack->size_a))
		destroy(stack, NULL);
	if (!isalldigit(&argv[1]) || isduplicate(&argv[1])
		|| islargerthan_limits(&argv[1], stack))
		destroy(stack, "Error");
	return (1);
}
