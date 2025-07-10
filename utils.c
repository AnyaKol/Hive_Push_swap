/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:48:43 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/09 19:05:56 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int nmem)
{
	t_stack *stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->nmem = 0;
	stack->values = ft_calloc(nmem, sizeof(int));
	if (stack->values == NULL)
		return (NULL);
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	if (stack->values != NULL)
	{
		free(stack->values);
		stack->values = NULL;
	}
	free(stack);
	stack = NULL;
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->nmem)
	{
		ft_printf("%i ", stack->values[i]);
		i++;
	}
	ft_printf("\n");
}

bool	ft_issorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->nmem)
	{
		if (stack->values[i] <= stack->values[i - 1])
			return (false);
		i++;
	}
	return (true);
}
