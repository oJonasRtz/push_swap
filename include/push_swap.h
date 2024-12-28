/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:49:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/28 14:07:01 by jopereir         ###   ########.fr       */
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
	int	*sorted;
}	t_stack;

//	Initiate the stack
void	stack_init(char **s, t_stack *stack);

//	Check funtions
int		already_sorted(t_stack *stack, int first, int last);
int		is_sorted(int *stack, int size);
void	cpy_stack(int *dest, int *src, int size);

//	Validation
int		is_less_than_int_min(int n, char *str);
int		validate_stack(t_stack *stack, char **argv);
int		is_larger_than_int_max(int n, char *str);

//	Operations funtions
void	ft_swap(int **n, int array_size);
void	ft_push(int **src, int **dest, int *src_size, int *dest_size);
void	ft_rotate(int **n, int array_size);
void	ft_reverse_rotate(int **n, int array_size);

//	Solve utils
int		get_bigger_index(int *n, int array_size);
int		get_smaller_index(int *n, int array_size);
int		partially_sorted(t_stack *stack);
void	double_operation(t_stack *stack,
			void (*f)(t_stack *, int), int n, int flag);
void	move_smaller_to_b(t_stack *stack, int flag);
void	move_to_top(t_stack *stack, int num, char a_or_b);
void	reverse_quicksort(int *array, int low, int high);
int		get_first(t_stack *stack, int *temp, int len);
int		get_last(t_stack *stack, int *temp, int len);
int		get_least_moves(int size, int index);
int		get_index(int *stack, int n);
int		min(int *stack, int size);
int		max(int *stack, int size);
int		check_best_push(t_stack *stack);;

//	Operataions
void	ft_sa(t_stack *stack, int flag);
void	ft_sb(t_stack *stack, int flag);
void	ft_ss(t_stack *stack, int flag);
void	ft_rra(t_stack *stack, int flag);
void	ft_rrb(t_stack *stack, int flag);
void	ft_rrr(t_stack *stack, int flag);
void	ft_ra(t_stack *stack, int flag);
void	ft_rb(t_stack *stack, int flag);
void	ft_rr(t_stack *stack, int flag);
void	ft_pb(t_stack *stack, int flag);
void	ft_pa(t_stack *stack, int flag);

//	Solve functions
void	tiny_sort(t_stack *stack);
void	large_sort(t_stack *stack);

//	Program run
int		create(char **argv, t_stack *stack);
int		execute(t_stack *stack);
int		destroy(t_stack *stack, char *message);

#endif
