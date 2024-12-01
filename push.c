/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:00:57 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 16:27:54 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	move the numbers of an array to right 
		leting the fisrt slot free

	1 2 3
	0 1 2 3
*/
static int	*ft_shift_right(int **n, int size)
{
	int	*stack;
	int	i;

	stack = ft_calloc(size + 1, sizeof(int));
	i = size - 1;
	while (i >= 0)
	{
		stack[i + 1] = (*n)[i];
		i--;
	}
	return (stack);
}

/*
	Moves the array to the left
		erasing the fisrt element

	1 2 3
	2 3
*/
static int	*ft_shift_left(int **n, int size)
{
	int	*stack;
	int	i;

	stack = ft_calloc(size - 1, sizeof(int));
	i = 0;
	while (i < size - 1)
	{
		stack[i] = (*n)[i + 1];
		i++;
	}
	return (stack);
}

/*
	ft_printf("push\n"); for tests
*/
void	ft_push(int **src, int **dest, int array_size)
{
	int	*temp;

	if (array_size < 2 || !*src)
		return ;
	temp = ft_shift_right(dest, array_size);
	(*dest)[0] = (*src)[0];
	*dest = temp;
	free(temp);
	temp = ft_shift_left(src, array_size);
	*src = temp;
	free(temp);
	ft_printf("push\n");
}
