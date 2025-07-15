/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:47:45 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/10 09:07:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_push(t_stack *to, t_stack *from);
static void	ft_rotate(t_stack *stack);
static void	ft_rotate_rev(t_stack *stack);

char	*get_commands(void)
{
	char	*command;
	char	*command_list;

	command_list = "";
	ft_printf("here\n");
	while (true)
	{
		command = get_next_line(1);
		ft_printf("%s", command);
		if (!ft_strncmp(command, "(null)", 6) || !ft_strncmp(command, "", 1))
			break ;
		command_list = ft_strjoin(command_list, command);
		free(command);
	}
	return (command_list);
}

void	stack_command(char *command, t_stack *a, t_stack *b)
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
	else
		print_error();
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
