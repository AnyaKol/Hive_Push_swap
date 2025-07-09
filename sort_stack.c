/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/09 17:26:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int nmem);
void	free_stack(t_stack *stack);
void	leave_longest_chain(t_stack *a, t_stack *b);
bool	find_longest_chain(int *values, int *chain, int nmem, int *max_len);

void	sort_stack(t_stack *a)
{	
	t_stack	*b;

	b = create_stack(a->nmem);	
	if (b == NULL)
		return ;
	leave_longest_chain(a, b);
	free_stack(b);
}

void	leave_longest_chain(t_stack *a, t_stack *b)
{
	t_stack	*chain;
	int	i;
	(void) b;

	chain = create_stack(a->nmem);
	if (chain == NULL)
		return ;
	i = 0;
	while (i < a->nmem)
	{
		find_longest_chain(&a->values[i], chain->values, a->nmem - i, &chain->nmem);
		i++;
	}
	ft_printf("Lenth: %i\n", chain->nmem);
	i = 0;
	while (i < chain->nmem)
	{
		ft_printf("%i ", chain->values[i]);
		i++;
	}
	//apply_chain(a, b, chain);
	free_stack(chain);
}

bool	find_longest_chain(int *values, int *chain, int nmem, int *max_len)
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
			if (find_longest_chain(&values[i], &chain[1], nmem - i, max_len))
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
