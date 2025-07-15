/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/15 12:57:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_memo(int *values, int nmem, t_stack **memo);
static void	apply_chain(t_stack *a, t_stack *b, t_stack *chain);
static bool	check_swap(int *values, int nmem, int num, int compare);
static void	apply_swap(t_stack *a, t_stack *b, t_stack *chain);

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
	int	size;

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
				size = max * sizeof(int);
				ft_memcpy(&memo[0]->values[1], memo[i]->values, size);
			}
		}
		i++;
	}
	memo[0]->values[0] = values[0];
	memo[0]->nmem = max + 1;
}

static void	apply_chain(t_stack *a, t_stack *b, t_stack *chain)
{
	while (a->nmem > chain->nmem)
	{
		apply_swap(a, b, chain);
		if (ft_issorted(*a))
			return ;
		if (stack_contains(chain, a->values[0]))
			apply_command("ra", a, b);
		else
			apply_command("pb", a, b);
	}
}

static void	apply_swap(t_stack *a, t_stack *b, t_stack *chain)
{
	bool	swap_a;
	bool	swap_b;

	swap_a = check_swap(a->values, a->nmem, a->values[1], a->values[0]);
	swap_b = check_swap(b->values, b->nmem, b->values[0], b->values[1]);
	if (swap_a)
	{
		if (swap_b)
			apply_command("ss", a, b);
		else
			apply_command("sa", a, b);
		if (stack_contains(chain, a->values[1]))
		{
			chain->values[chain->nmem] = a->values[0];
			chain->nmem += 1;
		}
		else if (stack_contains(chain, a->values[0]))
		{
			chain->values[chain->nmem] = a->values[1];
			chain->nmem += 1;
		}
	}
	else if (swap_b)
		apply_command("sb", a, b);
}

static bool	check_swap(int *values, int nmem, int num, int compare)
{
	int		i;
	int		min;
	bool	found;

	if (nmem < 3)
		return (false);
	i = 0;
	min = INT_MAX;
	found = false;
	while (i < nmem)
	{
		if (num < values[i] && values[i] <= min)
		{
			min = values[i];
			found = true;
		}
		i++;
	}
	if (found && min == compare)
		return (true);
	return (false);
}
