/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:13:23 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/06 17:33:37 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	call_commands(t_stack *stack, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_sa(stack, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_sa(stack, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(stack, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_ra(stack, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rb(stack, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(stack, 0);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		ft_rra(stack, 0);
	else if (ft_strncmp(line, "rrb\n", 3) == 0)
		ft_rrb(stack, 0);
	else if (ft_strncmp(line, "rrr\n", 3) == 0)
		ft_rrr(stack, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pa(stack, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pb(stack, 0);
	else
		return (1);
	return (0);
}

void	read_terminal(t_stack *stack)
{
	char	*temp;

	temp = get_next_line(0, 0);
	while (1)
	{
		if (temp == NULL)
			break ;
		if (call_commands(stack, temp))
		{
			get_next_line(0, 1);
			free(temp);
			destroy_bonus(stack, "Error");
		}
		free(temp);
		temp = get_next_line(0, 0);
	}
	free(temp);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2)
		return (1);
	create_bonus(&stack, argv);
	return (0);
}
