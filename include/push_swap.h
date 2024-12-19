/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:49:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/19 15:46:22 by jopereir         ###   ########.fr       */
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
}	t_stack;

//	Initiate the stack
void	stack_init(char **s, t_stack *stack);

//	Check funtions
int		already_sorted(t_stack *stack, int n);

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
int		get_bigger_num(int *n, int array_size);
int		get_smaller_num(int *n, int array_size);
int		partially_sorted(t_stack *stack);
void	double_operation(t_stack *stack,
			void (*f)(t_stack *, int), int n, int flag);
void	move_smaller_to_b(t_stack *stack, int flag);
void	move_smaller_to_top(t_stack *stack, int flag);

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

//	Cases functions
void	ft_case3(t_stack *stack);
void	ft_case5(t_stack *stack);

//	Program run
int		create(char **argv, t_stack *stack);
int		execute(t_stack *stack);
int		destroy(t_stack *stack, char *message);

#endif
