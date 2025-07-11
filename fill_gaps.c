/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_gaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/11 09:09:29 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cost	find_cheapest(t_stack *a, t_stack *b);
static t_cost	min_cost(t_cost index, int nmem_a, int nmem_b);
static void		rotate_repeat(t_cost *index, t_stack *a, t_stack *b);

void	fill_gaps(t_stack *a, t_stack *b)
{
	t_cost	index;

	while (b->nmem != 0)
	{
		index = find_cheapest(a, b);
		rotate_repeat(&index, a, b);
		rotate_stack(index, a, b);
		apply_command("pa", a, b);
	}
}

static void	rotate_repeat(t_cost *index, t_stack *a, t_stack *b)
{
	int	i;
	int	repeat;

	i = 0;
	if ((index->a > 0) == (index->b > 0))
	{
		if (index->a > 0)
			repeat = ft_min(index->a, index->b);
		else
			repeat = ft_max(index->a, index->b);
		while (i < abs(repeat))
		{
			if (index->a > 0)
				apply_command("rr", a, b);
			else
				apply_command("rrr", a, b);
			i++;
		}
		index->a -= repeat;
		index->b -= repeat;
	}
}

static t_cost	find_cheapest(t_stack *a, t_stack *b)
{
	int	i;
	t_cost	index;
	t_cost	cheapest;

	i = 0;
	cheapest.cost = a->nmem + b->nmem;
	while (i < b->nmem)
	{
		index.a = index_in_stack(b->values[i], a);
		index.b = i;
		index = min_cost(index, a->nmem - index.a, b->nmem - index.b);
		if (index.cost < cheapest.cost)
			cheapest = index;
		i++;
	}
	return (cheapest);
}

static t_cost	min_cost(t_cost index, int rev_a, int rev_b)
{
	t_cost	min;

	min = index;
	min.cost = index.a + index.b - ft_min(index.a, index.b);
	index.cost = index.a + rev_b;
	if (index.cost < min.cost)
	{
		min.cost = index.cost;
		min.a = index.a;
		min.b = -rev_b;
	}
	index.cost = rev_a + index.b;
	if (index.cost < min.cost)
	{
		min.cost = index.cost;
		min.a = -rev_a;
		min.b = index.b;
	}
	index.cost = rev_a + rev_b - ft_min(rev_a, rev_b);
	if (index.cost < min.cost)
	{
		min.cost = index.cost;
		min.a = -rev_a;
		min.b = -rev_b;
	}
	return (min);
}
