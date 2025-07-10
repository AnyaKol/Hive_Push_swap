/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/10 17:05:01 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_gaps(t_stack *a, t_stack *b);
static s_cost	find_cheapest(t_stack *a, t_stack *b);
static int	place_in_stack(int num, t_stack *stack);
static void	min_cost(t_cost *index, int nmem_a, int nmem_b);

void	sort_stack(t_stack *a)
{	
	t_stack	*b;

	b = create_stack(a->nmem);	
	if (b == NULL)
		return ;
	ft_printf("\nFind longest chain:\n");
	leave_chain(a, b);
	ft_printf("a: ");
	print_stack(a);
	ft_printf("b: ");
	print_stack(b);
	ft_printf("\nFill gaps:\n");
	fill_gaps(a, b);
	ft_printf("a: ");
	print_stack(a);
	ft_printf("b: ");
	print_stack(b);
	free_stack(b);
}

static void	fill_gaps(t_stack *a, t_stack *b)
{
	t_cost	cheapest;
	int		i;

	i = 0;
	while (b->nmem != 0)
	{
		cheapest = find_cheapest(a, b);
		rotate_stack(cheapest, a, b);
		while (i < min)
		{
			if (i > 0)
			{
				apply_command("rb", a, b);
				i--;
			}
			else
			{
				apply_command("rrb", a, b);
				i++;
			}
		}
		i = find_cost(b->values[0], a);
		while (abs(i) > 0)
		{
			if (i > 0)
			{
				apply_command("ra", a, b);
				i--;
			}
			else
			{
				apply_command("rra", a, b);
				i++;
			}
		}
		apply_command("pa", a, b);
	}
}

void	rotate_stack()
{
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
		index.a = place_in_stack(b->values[i], a);
		index.b = i;
		min_cost(&index, a->nmem, b->nmem);
		if (index.cost < cheapest.cost)
			cheapest = index;
		i++;
	}
	return (cheapest);
}

static int	place_in_stack(int num, t_stack *stack)
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

void	min_cost(t_cost *index, int nmem_a, int nmem_b)
{
	int	min;
	int	rev_a;
	int	rev_b;

	rev_a = nmem_a - index->a;
	rev_b = nmem_b - index->b;
	index->cost = index->a + index->b - ft_min(index->a, index->b);
	min = rev_a + rev_b - ft_min(rev_a, rev_b);
	if (min < index->cost)
	{
		index->cost = min;
		index->a = -rev_a;
		index->b = -rev_b;
	}
	min = index->a + rev_b;
	if (min < index->cost)
	{
		index->cost = min;
		index->b = -rev_b;
	}
	min = rev_a + index->b;
	if (min < index->cost)
	{
		index->cost = min;
		index->a = -rev_a;
	}
}
