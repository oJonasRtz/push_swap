/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/27 14:23:35 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_least_moves(int size, int index)
{
	if (size - index < index)
		return (size - index);
	return (index);
}

// static int	cpy_stack2(int *dest, int *src, int start, int end)
// {
// 	int	i;

// 	i = 0;
// 	while (start < end)
// 	{
// 		dest[i] = src[start];
// 		i++;
// 		start++;
// 	}
// 	return (i);
// }

// static void	init_temp(t_temp_stack *temp_a,
// 	t_temp_stack *temp_b, t_stack *stack)
// {
// 	int	*temp;

// 	temp = ft_calloc(stack->size_a, sizeof(int));
// 	cpy_stack(temp, stack->a, stack->size_a);
// 	ft_quicksort(temp, 0, stack->size_a - 1);
// 	temp_b->len = cpy_stack2(temp_b->stack, temp, 0, stack->size_a / 2);
// 	temp_a->len = cpy_stack2(temp_a->stack, temp,
// 			stack->size_a / 2 + (stack->size_a % 2 != 0), stack->size_a);
// 	reverse_quicksort(temp_b->stack, 0, temp_b->len - 1);
// 	free(temp);
// }

// static void	move_to_b(t_stack *stack, int *temp_b, int len)
// {
// 	int	first;
// 	int	last;
// 	int	min_dist;

// 	first = get_first(stack, temp_b, len);
// 	last = get_last(stack, temp_b, len);
// 	min_dist = first;
// 	if (min_dist == 0)
// 		return (ft_pb(stack, 1));
// 	if (get_least_moves(stack->size_a, last) < first)
// 		min_dist = last;
// 	move_to_top(stack, min_dist, 'a');
// 	ft_pb(stack, 1);
// }

// void	large_sort(t_stack *stack)
// {
// 	t_temp_stack	temp_a;
// 	t_temp_stack	temp_b;
// 	int				i;
// 	int				op;

// 	temp_b.stack = ft_calloc(stack->size_a / 2, sizeof(int));
// 	temp_a.stack = ft_calloc(stack->size_a / 2
// 			+ (stack->size_a % 2 != 0), sizeof(int));
// 	init_temp(&temp_a, &temp_b, stack);
// 	op = temp_b.len;
// 	i = 0;
// 	while (i < temp_b.len)
// 	{
// 		move_to_b(stack, temp_b.stack, op);
// 		i++;
// 	}
// 	solve(stack, &temp_a, &temp_b, 0);
// 	double_operation(stack, &ft_pa, op, 1);
// 	ft_double_free(temp_a.stack, temp_b.stack);
// }

static void	check_duo_a(t_stack *stack, int i)
{
	if (stack->a[0] > stack->a[1])
		ft_sa(stack, 1);
	double_operation(stack, &ft_ra, 2, 1);
	i++;
	if (i >= stack->size_a)
	{
		if (stack->size_a % 2 != 0
			&& get_smaller_num(stack->a, stack->size_a) != 0)
			ft_ra(stack, 1);
		if (stack->a[0] > stack->a[2])
			double_operation(stack, &ft_ra, 2, 1);
		return ;
	}
	return (check_duo_a(stack, i));
}

static void	check_duo_b(t_stack *stack, int i)
{
	if (stack->b[0] > stack->b[1])
		ft_sb(stack, 1);
	double_operation(stack, &ft_rb, 2, 1);
	i++;
	if (i >= stack->size_b)
	{
		if (stack->b[0] > stack->b[2])
			double_operation(stack, &ft_rb, 2, 1);
		return ;
	}
	return (check_duo_b(stack, i));
}

// static void	solve(t_stack *stack, int i)
// {
// 	ft_pa(stack, 1);
// 	if (stack->a[0] > stack->a[1])
// 		ft_sa(stack, 1);
// 	i++;
// 	if (i >= stack->size_a)
// 		return ;
// 	return (solve(stack, i));
//}

void	large_sort(t_stack *stack)
{
	check_duo_a(stack, 0);
	sort_a(stack);
	check_duo_b(stack, 0);
	// solve(stack, 0);
}
