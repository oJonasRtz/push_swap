/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_least_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:49 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/03 15:23:49 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_strcat(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (!s)
		return (NULL);
	free(s1);
	return (s);
}

char	*ft_get_strcat2(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (!s)
		return (NULL);
	free(s1);
	free(s2);
	return (s);
}

/*
	condition && (a || b) is useless, I just did it to silence Werror
*/
void	ft_least_moves(t_stack *stack)
{
	char	*operations;

	operations = ft_calloc(1, 1);
	if (stack->size_a == 2)
		operations = ft_get_strcat(operations, ft_sa(stack));
	else if (stack->size_a== 3)
		operations = ft_get_strcat2(operations, ft_case3(stack));
	else if (stack->size_a == 5)
		operations = ft_get_strcat2(operations, ft_case5(stack));
	if (issorted(stack->a, stack->size_a))
		ft_printf("%s", operations);
	free(operations);
}
