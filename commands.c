/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:47:45 by akolupae          #+#    #+#             */
/*   Updated: 2025/06/19 16:26:22 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack *to, t_stack *from);
//static void	ft_rotate(int *arr, int nmem);
//static void	ft_rotate_rev(int *arr, int nmem);
//static int	find_last(int *arr, int nmem);

void	apply_command(char *command, t_stack *a, t_stack *b)
{
	/*
	if (ft_strncmp(command, "sa", 3) == 0)
		ft_swap(&arra[0], &arra[1]);
	else if (ft_strncmp(command, "sb", 3) == 0)
		ft_swap(&arrb[0], &arrb[1]);
	else if (ft_strncmp(command, "ss", 3) == 0)
	{
		ft_swap(&arra[0], &arra[1]);
		ft_swap(&arrb[0], &arrb[1]);
	}
	*/
	if (ft_strncmp(command, "pa", 3) == 0)
	{
		ft_push(a, b);
		ft_printf("pa\n");
	}
	else if (ft_strncmp(command, "pb", 3) == 0)
	{
		ft_push(b, a);
		ft_printf("pb\n");
	}
	/*
	else if (ft_strncmp(command, "ra", 3) == 0)
		ft_rotate(arra, nmem);
	else if (ft_strncmp(command, "rb", 3) == 0)
		ft_rotate(arrb, nmem);
	else if (ft_strncmp(command, "rr", 3) == 0)
	{
		ft_rotate(arra, nmem);
		ft_rotate(arrb, nmem);
	}
	else if (ft_strncmp(command, "rra", 3) == 0)
		ft_rotate_rev(arra, nmem);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		ft_rotate_rev(arrb, nmem);
	else if (ft_strncmp(command, "rrr", 3) == 0)
	{
		ft_rotate_rev(arra, nmem);
		ft_rotate_rev(arrb, nmem);
	}
	*/
}

static void	ft_push(t_stack *to, t_stack *from)
{
	int	i;

	if (!to || !from || from->nmem == 0)
		return ;
	i = to->nmem;
	while (i > 0)
	{
		ft_swap(&to->values[i], &to->values[i - 1]);
		i--;
	}
	to->nmem += 1;
	ft_swap(&to->values[0], &from->values[0]);
	while (i < from->nmem - 1)
	{
		ft_swap(&from->values[i], &from->values[i + 1]);
		i++;
	}
	from->nmem -= 1;
}
/*
static void	ft_rotate(int *arr, int nmem)
{
	int	i;
	int	last;

	i = 0;
	last = find_last(arr, nmem);
	while (i < last - 1)
	{
		ft_swap(&arr[i], &arr[i + 1]);
		i++;
	}
}

static void	ft_rotate_rev(int *arr, int nmem)
{
	int	i;

	i = find_last(arr, nmem) - 1;
	while (i > 0)
	{
		ft_swap(&arr[i], &arr[i - 1]);
		i--;
	}
}

static int	find_last(int *arr, int nmem)
{
	int	i;

	i = 0;
	while (i < nmem)
	{
		if (arr[i] == 0)
			break ;
		i++;
	}
	return (i);
}
*/
