/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_chain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/14 18:28:17 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_memo(int *values, int nmem, t_stack **memo);
static void	apply_chain(t_stack *a, t_stack *b, t_stack *chain);
static bool	stack_contains(t_stack *stack, int num);

void	find_chain(t_stack *a, t_stack *b)
{
	t_stack	**memo;
	t_stack	*chain;
	int		max;
	int		i;

	i = 0;
	max = 0;
	memo = create_memo(a);
	if (memo == NULL)
		return ;
	while (i < a->nmem)
	{
		fill_memo(&a->values[i], a->nmem - i, &memo[i]);
		if (memo[i]->nmem > max)
		{
			chain = memo[i];
			max = chain->nmem;
		}
		i++;
	}
	apply_chain(a, b, chain);
	free_memo(memo, a->nmem);
}

static void	fill_memo(int *values, int nmem, t_stack **memo)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i < nmem)
	{
		if (values[i] > values[0])
		{
			if (memo[i]->nmem == 0)
				fill_memo(&values[i], nmem - i, &memo[i]);
			if (memo[i]->nmem > max)
			{
				max = memo[i]->nmem;
				ft_memcpy(&memo[0]->values[1], memo[i]->values, max * sizeof(int));
			}
		}
		i++;
	}
	memo[0]->values[0] = values[0];
	memo[0]->nmem = max + 1;
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
}

static bool	stack_contains(t_stack *stack, int num)
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


