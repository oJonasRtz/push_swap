/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:32:23 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 12:43:55 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_ra(int *a, int array_size)
{
	ft_rotate(a, array_size);
	return ("ra\n");
}

char	*ft_pb(int *a, int *b, int array_size)
{
	ft_push(&a, &b, array_size);
	return ("pb\n");
}

char	*ft_pa(int *a, int *b, int array_size)
{
	ft_push(&b, &a, array_size);
	return ("pa\n");
}
