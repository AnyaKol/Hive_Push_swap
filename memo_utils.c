/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:48:43 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/15 12:55:22 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int nmem)
{
	t_stack	*stack;

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

t_stack	**create_memo(t_stack *a)
{
	int		i;
	t_stack	**memo;

	memo = ft_calloc(a->nmem, sizeof(t_stack *));
	if (memo == NULL)
		return (NULL);
	i = 0;
	while (i < a->nmem)
	{
		memo[i] = create_stack(a->nmem - i);
		if (memo[i] == NULL)
		{
			free_memo(memo, a->nmem);
			return (NULL);
		}
		i++;
	}
	return (memo);
}

void	free_memo(t_stack **memo, int nmem)
{
	int	i;

	i = 0;
	while (i < nmem)
	{
		free_stack(memo[i]);
		i++;
	}
	free(memo);
}
