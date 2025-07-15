/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:16:35 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/15 19:02:05 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*values;
	int	nmem;
}	t_stack;

char	*get_commands(void);
void	stack_command(char *command, t_stack *a, t_stack *b);
t_stack	*create_stack(int nmem);
void	free_stack(t_stack *stack);
int		print_error(void);

#endif
