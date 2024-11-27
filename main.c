/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:42 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/27 10:46:07 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	ft_print_graph(int *a, int *b, int size)
{
	int	i;

	i = 0;
	ft_printf("a  b\n----\n");
	while (i < size)
	{
		ft_printf("%d  %d\n", a[i], b[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	size;

	size = 0;
	if (argc < 2)
		exit (1);
	else
		a = stack_init(argv, &size);
	b = ft_calloc(size, sizeof(int));
	ft_printf("Original\n");
	ft_print_graph(a, b, size);
	ft_printf("\nModificado\n");
	ft_reverse_rotate(a, size);
	ft_print_graph(a, b, size);
	ft_printf("\n");
	ft_double_free(a, b);
	return (0);
}
