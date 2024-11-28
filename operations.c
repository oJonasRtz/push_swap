/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:55:19 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/28 12:43:06 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_ss(int *a, int *b, int array_size)
{
	ft_swap(a, array_size);
	ft_swap(b, array_size);
	return ("ss\n");
}

char	*ft_rr(int *a, int *b, int array_size)
{
	ft_rotate(a, array_size);
	ft_rotate(b, array_size);
	return ("rr\n");
}

char	*ft_rrr(int *a, int *b, int array_size)
{
	ft_reverse_rotate(a, array_size);
	ft_reverse_rotate(b, array_size);
	return ("rrr\n");
}

char	*ft_sa(int *a, int array_size)
{
	ft_swap(a, array_size);
	return ("sa\n");
}

char	*ft_rra(int *a, int array_size)
{
	ft_reverse_rotate(a, array_size);
	return ("rra\n");
}
