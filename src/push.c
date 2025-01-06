/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:00:57 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/06 14:25:02 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	move the numbers of an array to right 
		leting the fisrt slot free

	1 2 3
	0 1 2 3
*/
static void	ft_shift_right(int **n, int *size)
{
	int	*stack;
	int	i;

	stack = ft_calloc(*size + 1, sizeof(int));
	if (!stack)
		return ;
	i = *size - 1;
	while (i >= 0)
	{
		stack[i + 1] = (*n)[i];
		i--;
	}
	free(*n);
	*n = stack;
}

/*
	Moves the array to the left
		erasing the fisrt element

	1 2 3
	2 3
*/
static void	ft_shift_left(int **n, int *size)
{
	int	*stack;
	int	i;

	stack = ft_calloc(*size - 1, sizeof(int));
	if (!stack)
		return ;
	i = 0;
	while (i < *size - 1)
	{
		stack[i] = (*n)[i + 1];
		i++;
	}
	free(*n);
	*n = stack;
}

/*
	ft_printf("push\n"); for tests
*/
void	ft_push(int **src, int **dest, int *src_size, int *dest_size)
{
	if (*src_size < 1 || !*src)
		return ;
	if (!*dest)
		*dest = ft_calloc(*dest_size + 1, sizeof(int));
	else
		ft_shift_right(dest, dest_size);
	(*dest_size)++;
	(*dest)[0] = (*src)[0];
	ft_shift_left(src, src_size);
	(*src_size)--;
	if ((*src_size) == 0)
		(*src) = NULL;
}

void	ft_pa(t_stack *stack, int flag)
{
	ft_push(&stack->b, &stack->a, &stack->size_b, &stack->size_a);
	if (flag)
	{
		stack->ocnt++;
		ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *stack, int flag)
{
	ft_push(&stack->a, &stack->b, &stack->size_a, &stack->size_b);
	if (flag)
	{
		stack->ocnt++;
		ft_printf("pb\n");
	}
}
