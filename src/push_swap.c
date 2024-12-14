/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:42 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:19 by jopereir         ###   ########.fr       */
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

	if (argc != 2)
		exit (0);
	program_create(argv[1], &stack);
	return (0);
}
