/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:45:28 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 13:40:29 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Takes the fisrt element and move to the end of the array

	input: 1, 2, 3, 4, 5
	output: 2, 3, 4, 5, 1
*/
void	ft_rotate(int **n, int array_size)
{
	int	temp;
	int	i;

	if (array_size < 2)
		return ;
	temp = (*n)[0];
	i = 0;
	while (i < array_size - 1)
	{
		(*n)[i] = (*n)[i + 1];
		i++;
	}
	(*n)[i] = temp;
}
