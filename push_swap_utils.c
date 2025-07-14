/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:48:43 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/11 08:56:10 by akolupae         ###   ########.fr       */
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

t_stack	**create_memo(t_stack *a)
{
	int	i;
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

int	index_in_stack(int num, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->nmem)
	{
		if ((stack->values[i - 1] < num && num < stack->values[i])
			|| (stack->values[i - 1] > stack->values[i]
				&& (stack->values[i - 1] < num || num < stack->values[i])))
			break ;
		i++;
	}
	return (i);
}

void	rotate_stack(t_cost index, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < abs(index.a))
	{
		if (index.a > 0)
			apply_command("ra", a, b);
		else
			apply_command("rra", a, b);
		i++;
	}
	if (b == NULL)
		return ;
	i = 0;
	while (i < abs(index.b))
	{
		if (index.b > 0)
			apply_command("rb", a, b);
		else
			apply_command("rrb", a, b);
		i++;
	}
}






void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->nmem)
	{
		ft_printf(" %i", stack->values[i]);
		i++;
	}
	ft_printf("\n");
}

bool	ft_issorted(t_stack stack)
{
	int	i;

	i = 1;
	while (i < stack.nmem)
	{
		if (stack.values[i] < stack.values[i - 1])
			return (false);
		i++;
	}
	return (true);
}
