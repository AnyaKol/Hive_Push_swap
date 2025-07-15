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

bool	ft_issorted(t_stack stack)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < stack.nmem)
	{
		if (stack.values[i] < stack.values[min])
			min = i;
		i++;
	}
	i = min + 1;
	while (i != min && i - stack.nmem != min)
	{
		if (i >= stack.nmem)
			i -= stack.nmem;
		if (i == 0 && stack.values[0] < stack.values[stack.nmem - 1])
			return (false);
		else if (stack.values[i] < stack.values[i - 1])
			return (false);
		i++;
	}
	return (true);
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
