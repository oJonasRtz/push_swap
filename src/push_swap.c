/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:42 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/03 15:22:12 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /*
// 	ft_print_graph is a temporary funtion for tests
// */
// static void	ft_print_graph(int *a, int *b, int size)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("a  b\n----\n");
// 	while (i < size)
// 	{
// 		ft_printf("%d  %d\n", a[i], b[i]);
// 		i++;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc <= 2 || already_sorted(&argv[1]))
		exit (0);
	if (!isalldigit(&argv[1]) || isduplicate(&argv[1])
		|| islargerthan_limits(&argv[1]))
		exit(ft_printf("Error\n"));
	stack.a = stack_init(argv, &stack.size_a);
	stack.b = NULL;
	stack.size_b = 0;
	ft_least_moves(&stack);
	ft_double_free(stack.a, stack.b);
	return (0);
}
