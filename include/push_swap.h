/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:49:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/02 14:07:55 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
}	t_stack;

//	Initiate the stack
int		*stack_init(char **s, int *size);

//	Check funtions
int		isalldigit(char **s);
int		isduplicate(char **s);
int		islargerthan_limits(char **s);
int		already_sorted(char **s);
int		issorted(int *n, int array_size);

//	Operations funtions
void	ft_swap(int **n, int array_size);
void	ft_push(int **src, int **dest, int *src_size, int *dest_size);
void	ft_rotate(int **n, int array_size);
void	ft_reverse_rotate(int **n, int array_size);

//	Solve utils
void	ft_least_moves(t_stack *stack);
int		get_bigger_num(int *n, int array_size);
int		get_smaller_num(int *n, int array_size);
char	*ft_get_strcat(char *s1, char *s2);
char	*ft_get_strcat2(char *s1, char *s2);
char	*partially_sorted(t_stack *stack);
char	*double_operation(t_stack *stack , char *(*f)(t_stack *), int n, int _return);
char	*random_sort(t_stack *stack);
char	*move_smaller_to_b(t_stack *stack);

//	Operataions
char	*ft_sa(t_stack *stack);
char	*ft_sb(t_stack *stack);
char	*ft_rra(t_stack *stack);
char	*ft_ra(t_stack *stack);
char	*ft_pb(t_stack *stack);
char	*ft_pa(t_stack *stack);

//	Cases functions
char	*ft_case3(t_stack *stack);
char	*ft_case5(t_stack *stack);

#endif
