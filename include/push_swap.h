/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:49:58 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/03 16:13:10 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	ocnt;
	int	operations_expected;
}	t_stack;

/*
	num and index is for stack a
	target is stack b
*/
typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	index_a;
	int	num_a;
	int	num_b;
	int	index_b;
}	t_cost;

//	events.c
int		create(char **argv, t_stack *stack);
int		execute(t_stack *stack);
int		destroy(t_stack *stack, char *message);

//	already_sorted.c
int		already_sorted(t_stack *stack, int first, int last);
void	cpy_stack(int *dest, int *src, int size);

//	best_push.c
t_cost	check_best_push(t_stack *stack);
int		get_target(t_stack *stack);

//	ft_init.c
void	stack_init(char **s, t_stack *stack);

//	ft_solve_high
void	large_sort(t_stack *stack);

//	ft_solve_high_utils.c
int		get_least_moves(int size, int index);
int		min(int *stack, int size);
int		max(int *stack, int size);
int		check1(t_stack *stack, t_cost *cost, int flag);
int		get_target_b(t_stack *stack, t_cost *cost);

//	ft_solve_low.c
void	tiny_sort(t_stack *stack);
void	move_smaller_to_b(t_stack *stack, int flag);

//	ft_solve_low_utils.c
int		get_bigger_index(int *n, int array_size);
int		get_smaller_index(int *n, int array_size);
int		get_index(int *stack, int n);
void	double_operation(t_stack *stack,
			void (*f)(t_stack *, int), int n, int flag);
int		partially_sorted(t_stack *stack);

//	move_both.c
int		get_smallest_value(int n, int n2);
void	move_both(t_stack *stack, t_cost *cost);

//	move_to_top.c
void	move_to_top(t_stack *stack, int num, char a_or_b);

//	push.c
void	ft_push(int **src, int **dest, int *src_size, int *dest_size);
void	ft_pa(t_stack *stack, int flag);
void	ft_pb(t_stack *stack, int flag);

//	reverse_rotate.c
void	ft_reverse_rotate(int **n, int array_size);
void	ft_rra(t_stack *stack, int flag);
void	ft_rrb(t_stack *stack, int flag);
void	ft_rrr(t_stack *stack, int flag);

//	rotate.c
void	ft_rotate(int **n, int array_size);
void	ft_ra(t_stack *stack, int flag);
void	ft_rb(t_stack *stack, int flag);
void	ft_rr(t_stack *stack, int flag);

//	swap.c
void	ft_swap(int **n, int array_size);
void	ft_sa(t_stack *stack, int flag);
void	ft_sb(t_stack *stack, int flag);
void	ft_ss(t_stack *stack, int flag);

//	validation.c
int		validate_stack(t_stack *stack, char **argv);

//	validation_utils.c
int		is_less_than_int_min(int n, char *str);
int		is_larger_than_int_max(int n, char *str);

#endif
