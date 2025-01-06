/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:13:33 by jopereir          #+#    #+#             */
/*   Updated: 2025/01/06 12:32:32 by jopereir         ###   ########.fr       */
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
void	read_terminal(t_stack *stack);

#endif
