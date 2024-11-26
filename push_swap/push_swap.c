/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:42 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:58:55 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

/*
	Returns the greater size of an array
*/
int	get_size(int *a, int *b, int *size_a, int *size_b)
{
	while (a != NULL && a[*size_a])
		(*size_a)++;
	while (b != NULL && b[*size_b])
		(*size_b)++;
	if (*size_b > *size_a)
		return (*size_b);
	return (*size_a);
}

void	draw_grid(int	*n1, int *n2)
{
	int	i;
	int	size_a;
	int	size_b;
	int	max_size;

	size_a = 0;
	size_b = 0;
	max_size = get_size(n1, n2, &size_a, &size_b);
	i = 0;
	while (i < max_size)
	{
		if (i < size_a)
			ft_printf("%d", n1[i]);
		else
			ft_printf(" ");
		if (i < size_b)
			ft_printf(" %d", n2[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("- -\na b\n");
}

void	ft_switch_format(char *s, int *a, int *b)
{
	if (ft_strncmp(s, "sa", ft_strlen(s)) == 0)
		ft_swap(a);
	else if (ft_strncmp(s, "sb", ft_strlen(s)) == 0)
		ft_swap(b);
	else if (ft_strncmp(s, "ss", ft_strlen(s)) == 0)
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (ft_strncmp(s, "pa", ft_strlen(s)) == 0)
		ft_push(&b, &a);
	else if (ft_strncmp(s, "pb", ft_strlen(s)) == 0)
		ft_push(&a, &b);
	draw_grid(a, b);
}

int	main(int argc, char *argv[])
{
	int		*a;
	int		*b;
	int		a_size;
	char	buffer[2];

	a_size = 0;
	if (argc < 2)
	{
		ft_printf("ERROR.\n");
		exit (1);
	}
	else
		a = stack_init(argv);
	b = ft_calloc(a_size, sizeof(int));
	draw_grid(a, b);
	ft_printf ("\nOperação: ");
	read(0, buffer, 2);
	ft_switch_format(buffer, a, b);
	ft_double_free(a, b);
	return (0);
}
