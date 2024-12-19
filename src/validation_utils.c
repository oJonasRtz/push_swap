/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:05:26 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/19 11:05:44 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_larger_than_int_max(int n, char *str)
{
	return (n == INT_MAX && ft_strncmp(str, "2147483647", 11) != 0);
}

int	is_less_than_int_min(int n, char *str)
{
	return (n == INT_MIN && ft_strncmp(str, "-2147483648", 12) != 0);
}
