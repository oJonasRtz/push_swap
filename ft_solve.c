/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:49:18 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 12:09:18 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Returns the index of the biggest number
*/
int	get_bigger_num(int *n, int array_size)
{
	int	i;
	int	index;

	index = 0;
	i = 1;
	while (i < array_size)
	{
		if (n[i] > n[index])
			index = i;
		i++;
	}
	return (index);
}

int	get_smaller_num(int *n, int array_size)
{
	int	i;
	int	index;

	index = 0;
	i = 1;
	while (i < array_size)
	{
		if (n[i] < n[index])
			index = i;
		i++;
	}
	return (index);
}

/*
	Solves a array of 3 numbers
*/
char	*ft_case3(int **a, int size)
{
	char	*operations;
	int		bigger_num;
	int		smaller_num;

	operations = ft_calloc (1, 1);
	bigger_num = get_bigger_num(*a, size);
	smaller_num = get_smaller_num(*a, size);
	if (bigger_num == size - 1)
		operations = ft_get_strcat(operations, ft_sa(*a, size));
	else if (bigger_num == 0 && smaller_num == size - 1)
			operations = ft_get_strcat(operations,
				ft_strjoin(ft_sa(*a, size), ft_rra(*a, size)));
	else if (bigger_num == 0 && smaller_num != size - 1)
			operations = ft_get_strcat(operations, ft_ra(*a, size));
	else if (smaller_num == 0)
		operations = ft_get_strcat(operations,
				ft_strjoin(ft_sa(*a, size), ft_ra(*a, size)));
	else
		operations = ft_get_strcat(operations, ft_rra(*a, size));
	return (operations);
}
