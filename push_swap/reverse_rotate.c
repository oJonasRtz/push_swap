/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:00:57 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/25 10:03:21 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Takes the fisrt element and move to the end of the array

	input: 1, 2, 3, 4, 5
	output: 5, 1, 2, 3, 4
*/
void	ft_reverse_rotate(int *n, int array_size)
{
	int	temp;
	int	temp2;
	int	i;

	if (array_size < 2)
		return ;
	temp = array_size - 1;
	i = temp;
	while (i > 0)
	{
		n[i] = n[i - 1];
		i--;
	}
	n[0] = temp;
}
