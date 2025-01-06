/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:13:33 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/06 14:39:10 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "libft.h"
# include <fcntl.h>

//	events_bonus.c
void	create_bonus(t_stack *stack, char **argv);
void	execute_bonus(t_stack *stack);
void	destroy_bonus(t_stack *stack, char *message);

//	checker.c
int		read_terminal(t_stack *stack);

#endif
