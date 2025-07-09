/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/09 19:06:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	leave_longest_chain(t_stack *a, t_stack *b);
static bool	find_longest_chain(int *values, int *chain, int nmem, int *max_len);
static void	apply_chain(t_stack *a, t_stack *b, t_stack *chain);

void	sort_stack(t_stack *a)
{	
	t_stack	*b;

	b = create_stack(a->nmem);	
	if (b == NULL)
		return ;
	leave_longest_chain(a, b);
	free_stack(b);
}

static void	leave_longest_chain(t_stack *a, t_stack *b)
{
	t_stack	*chain;
	int		i;

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
	ft_printf("\n");
	apply_chain(a, b, chain);
	print_stack(a);
	print_stack(b);
	free_stack(chain);
}

static bool	find_longest_chain(int *values, int *chain, int nmem, int *max_len)
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

static void	apply_chain(t_stack *a, t_stack *b, t_stack *chain)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a->nmem)
	{
		if (a->values[i] == chain->values[j])
		{
			i++;
			j++;
			continue ;
		}
		apply_command("pb", a, b);
		i++;
	}
}
