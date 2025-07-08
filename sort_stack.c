/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/08 19:16:33 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_empty_stack(int nmem);

void	sort_stack(t_stack *a)
{	
	t_stack	*b;
	t_stack *chain;

	b = create_empty_stack(a->nmem);	
	chain = create_empty_stack(a->nmem);
	if (b == NULL || chain == NULL)
		return ;
	chain = find_longest_chain(a, chain);
	apply_chain(a, b, chain);
}

static t_stack	*create_empty_stack(int nmem)
{
	t_stack stack;

	stack.nmem = 0;
	stack.values = ft_calloc(nmem, sizeof(int));
	if (stack.values == NULL)
		return (NULL);
	return (&stack);
}

static t_stack	find_longest_chain(t_stack *a, t_stack *chain)
{
	int		i;
	int		min;

	i = 1;
	min = 0;
	chain->values[0] = 0;
	while (i < a->nmem)
	{
		if (a->values[i] > a->values[min])
		{
			chain->values[1] = 1;
			min = 1;
			chain = find_longest_chain(&a->values[i], chain)
		}
	}
	i = 1;
	j = 0;
	max = a->values[0];
	while (i < a->nmem)
	{
		if (a->values[i] > max)
		{
			max = a->values[i];
			chain->values[j] = i;
			j++;
		}
		i++;
	}
}

