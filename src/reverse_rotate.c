/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:00:57 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 13:40:49 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Takes the fisrt element and move to the end of the array

	input: 1, 2, 3, 4, 5
	output: 5, 1, 2, 3, 4
*/
void	ft_reverse_rotate(int **n, int array_size)
{
	int	temp;
	int	i;

	if (array_size < 2)
		return ;
	temp = (*n)[array_size - 1];
	i = array_size - 1;
	while (i > 0)
	{
		(*n)[i] = (*n)[i - 1];
		i--;
	}
	(*n)[i] = temp;
}
