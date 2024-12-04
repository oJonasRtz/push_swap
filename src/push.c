/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:00:57 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/03 10:53:57 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	move the numbers of an array to right 
		leting the fisrt slot free

	1 2 3
	0 1 2 3
*/
static void	ft_shift_right(int **n, int size)
{
	int	*stack;
	int	i;

	stack = ft_calloc(size + 1, sizeof(int));
	if (!stack)
		return ;
	i = size - 1;
	while (i >= 0)
	{
		stack[i + 1] = (*n)[i];
		i--;
	}
	*n = stack;
}

/*
	Moves the array to the left
		erasing the fisrt element

	1 2 3
	2 3
*/
static void	ft_shift_left(int **n, int size)
{
	int	*stack;
	int	i;

	stack = ft_calloc(size - 1, sizeof(int));
	if (!stack)
		return ;
	i = 0;
	while (i < size - 1)
	{
		stack[i] = (*n)[i + 1];
		i++;
	}
	*n = stack;
}

/*
	ft_printf("push\n"); for tests
*/
void	ft_push(int **src, int **dest, int array_size)
{
	if (array_size < 2 || !*src)
		return ;
	ft_shift_right(dest, array_size);
	(*dest)[0] = (*src)[0];
	ft_shift_left(src, array_size);
}
