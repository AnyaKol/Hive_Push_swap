/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:47:45 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/16 19:08:11 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	check_command(char *command);
static void	stack_command(char *command, t_stack *a, t_stack *b);
static void	ft_push(t_stack *to, t_stack *from);
static void	ft_rotate(t_stack *stack);
static void	ft_rotate_rev(t_stack *stack);

bool	apply_commands(char *command_list, t_stack *a, t_stack *b)
{
	char	command[4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(command, 4 * sizeof(char));
	while (command_list[i] != '\0' && j < 4)
	{
		if (command_list[i] == '\n')
		{
			command[j] = '\0';
			if (!check_command(command))
				return (false);
			stack_command(command, a, b);
			j = 0;
		}
		else
		{
			command[j] = command_list[i];
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_command(char *command)
{
	const char	*all[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int	i;
	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(command, all[i], 3))
			return (true);
		i++;
	}
	ft_printf("no such command\n");
	return (false);
}

static void	stack_command(char *command, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(command, "sa", 3) || !ft_strncmp(command, "ss", 3))
		ft_swap(&a->values[0], &a->values[1]);
	else if (!ft_strncmp(command, "ra", 3) || !ft_strncmp(command, "rr", 3))
		ft_rotate(a);
	else if (!ft_strncmp(command, "rra", 3) || !ft_strncmp(command, "rrr", 3))
		ft_rotate_rev(a);
	else if (!ft_strncmp(command, "pa", 3))
		ft_push(a, b);
	else if (!ft_strncmp(command, "pb", 3))
		ft_push(b, a);
	if (!ft_strncmp(command, "sb", 3) || !ft_strncmp(command, "ss", 3))
		ft_swap(&b->values[0], &b->values[1]);
	else if (!ft_strncmp(command, "rb", 3) || !ft_strncmp(command, "rr", 3))
		ft_rotate(b);
	else if (!ft_strncmp(command, "rrb", 3) || !ft_strncmp(command, "rrr", 3))
		ft_rotate_rev(b);
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

static void	ft_rotate(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->nmem - 1)
	{
		ft_swap(&stack->values[i], &stack->values[i + 1]);
		i++;
	}
}

static void	ft_rotate_rev(t_stack *stack)
{
	int	i;

	i = stack->nmem - 1;
	while (i > 0)
	{
		ft_swap(&stack->values[i], &stack->values[i - 1]);
		i--;
	}
}
