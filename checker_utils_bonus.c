/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:48:43 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/16 18:52:47 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*create_stack(int nmem)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->nmem = 0;
	stack->values = ft_calloc(nmem, sizeof(int));
	if (stack->values == NULL)
	{
		ft_free(stack);
		return (NULL);
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	if (stack->values != NULL)
		ft_free(stack->values);
	ft_free(stack);
}

bool	check_command(char *command)
{
	const char	*all[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(command, all[i], 3))
			return (true);
		i++;
	}
	return (false);
}

bool	ft_issorted(const t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->nmem)
	{
		if (stack->values[i - 1] > stack->values[i])
			return (false);
		i++;
	}
	return (true);
}

int	clean_up(t_stack *a, t_stack *b, bool error)
{
	free_stack(a);
	free_stack(b);
	if (error)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
