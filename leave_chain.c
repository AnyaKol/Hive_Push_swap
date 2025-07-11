/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_chain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/11 12:44:22 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	find_chain(int *values, int *chain, int nmem, int *max_len);
static void	apply_chain(t_stack *a, t_stack *b, t_stack *chain);

void	leave_chain(t_stack *a, t_stack *b)
{
	t_stack	*chain;
	int		i;

	chain = create_stack(a->nmem);
	if (chain == NULL)
		return ;
	i = 0;
	while (i < a->nmem)
	{
		find_chain(&a->values[i], chain->values, a->nmem - i, &chain->nmem);
		i++;
	}
	apply_chain(a, b, chain);
	free_stack(chain);
}

static bool	find_chain(int *values, int *chain, int nmem, int *max_len)
{
	int	i;
	static int	len = 1;
	bool	save;

	i = 1;
	save = false;
	while (i < nmem)
	{
		if (values[i] > values[0])
		{
			len++;
			if (find_chain(&values[i], &chain[1], nmem - i, max_len))
			{
				save = true;
				chain[0] = values[0];
			}
			len--;
		}
		i++;
	}
	if (len > *max_len)
	{
		save = true;
		chain[0] = values[0];
		*max_len = len;
	}
	return (save);
}

static void	apply_chain(t_stack *a, t_stack *b, t_stack *chain)
{
	if (chain->nmem == a->nmem)
		return ;
	while (a->nmem > chain->nmem)
	{
		if (stack_contains(chain, a->values[0]))
			apply_command("ra", a, b);
		else
			apply_command("pb", a, b);
	}
	while (a->values[0] != chain->values[0])
		apply_command("pb", a, b);
}

bool	stack_contains(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->nmem)
	{
		if (stack->values[i] == num)
			return (true);
		i++;
	}
	return (false);
}
