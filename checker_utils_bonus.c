/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:48:43 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/16 18:52:47 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*create_stack(int nmem)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->nmem = 0;
	stack->values = ft_calloc(nmem, sizeof(int));
	if (stack->values == NULL)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	if (stack->values != NULL)
	{
		free(stack->values);
		stack->values = NULL;
	}
	free(stack);
	stack = NULL;
}

char	*get_commands(void)
{
	char	*command;
	char	*command_list;

	command_list = ft_calloc(1, 1);
	while (true)
	{
		command = get_next_line(1);
		if (!ft_strncmp(command, "(null)", 6))
		{
			free(command);
			command = NULL;
			break ;
		}
		command_list = ft_strjoin(command_list, command);
		free(command);
		command = NULL;
	}
	return (command_list);
}

bool	ft_issorted(const t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < stack->nmem)
	{
		if (stack->values[i] < stack->values[min])
			min = i;
		i++;
	}
	i = min + 1;
	while (i != min && i - stack->nmem != min)
	{
		if (i >= stack->nmem)
			i -= stack->nmem;
		if (i == 0 && stack->values[0] < stack->values[stack->nmem - 1])
			return (false);
		else if (i >= 0 && stack->values[i] < stack->values[i - 1])
			return (false);
		i++;
	}
	return (true);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}



void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->nmem)
	{
		ft_printf(" %i", stack->values[i]);
		i++;
	}
	ft_printf("\n");
}
