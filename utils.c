/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:48:43 by akolupae          #+#    #+#             */
/*   Updated: 2025/06/19 15:04:21 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_issorted(int *arr, int nmem)
{
	int	i;

	i = 1;
	while (i < nmem)
	{
		if (arr[i] < arr[i - 1])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_isempty(int *arr, int nmem)
{
	int	i;

	i = 0;
	while (i < nmem)
	{
		if (arr[i] != 0)
			return (false);
		i++;
	}
	return (true);
}

void	ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
