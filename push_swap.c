/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:42 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 14:14:39 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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
	int	*a;
	int	*b;
	int	size;

	if (argc <= 2 || already_sorted(&argv[1]))
		exit (0);
	if (!isalldigit(&argv[1]) || isduplicate(&argv[1])
		|| islargerthan_limits(&argv[1]))
		exit(ft_printf("Error\n"));
	a = stack_init(argv, &size);
	b = NULL;
	ft_least_moves(a, b, size);
	ft_double_free(a, b);
	return (0);
}
