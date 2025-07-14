/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/11 11:29:09 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a)
{	
	t_stack	*b;

	b = create_stack(a->nmem);	
	if (b == NULL)
		return ;
//	ft_printf("\nFind longest chain:\n");
	find_chain(a, b);
//	ft_printf("a: ");
//	print_stack(a);
//	ft_printf("b: ");
//	print_stack(b);
//	ft_printf("\nFill gaps:\n");
	fill_gaps(a, b);
//	ft_printf("a: ");
//	print_stack(a);
//	ft_printf("b: ");
//	print_stack(b);
	free_stack(b);
	rotate_to_start(a);
//	ft_printf("\nRotate to start:\n");
//	print_stack(a);
}

void	rotate_to_start(t_stack *a)
{
	int		i;
	t_cost	index;

	i = 1;
	while (i < a->nmem)
	{
		if (a->values[i] < a->values[i - 1])
			break ;
		i++;
	}
	if (i == a->nmem)
		return ;
	if (i > a->nmem - i)
		i = -(a->nmem - i);
	index.a = i;
	rotate_stack(index, a, NULL);
}
