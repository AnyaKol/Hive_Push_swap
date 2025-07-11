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

int	index_in_stack(int num, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->nmem)
	{
		if (num < stack->values[i] && num > stack->values[stack->nmem - 1 - i])
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
