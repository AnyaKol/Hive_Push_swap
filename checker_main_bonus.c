/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:16:18 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/16 19:07:00 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	check_args(char **args, int arg_num, t_stack *a);
static bool	check_repeat(const t_stack *stack);
static void	print_result(bool result);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command_list;

	if (argc <= 2)
		return (0);
	a = create_stack(argc - 1);
	if (a == NULL)
		return (0);
	a->nmem = argc - 1;
	if (!check_args(&argv[1], argc - 1, a) || !check_repeat(a))
	{
		free_stack(a);
		return (print_error());
	}
	print_stack(a);
	b = create_stack(argc - 1);
	if (b == NULL)
	{
		free_stack(a);
		return (0);
	}
	command_list = get_commands();
	if (command_list == NULL)
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	ft_printf("command list:\n%s", command_list);
	if (!apply_commands(command_list, a, b))
		print_error();
	else
		print_result(ft_issorted(a));
	ft_printf("a: \n");
	print_stack(a);
	free_stack(a);
	free_stack(b);
	free(command_list);
	return (0);
}

static bool	check_args(char **args, int arg_num, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg_num)
	{
		j = 0;
		if (args[i][j] == '-')
			j++;
		while (args[i][j] != '\0')
		{
			if (!ft_isdigit(args[i][j]))
				return (false);
			j++;
		}
		stack->values[i] = ft_atoi(args[i]);
		if (stack->values[i] == 0 && j > 2)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_repeat(const t_stack *stack)
{
	int	i;
	int	j;
	int	current_num;

	i = 0;
	while (i < stack->nmem - 1)
	{
		current_num = stack->values[i];
		j = i + 1;
		while (j < stack->nmem)
		{
			if (current_num == stack->values[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static void	print_result(bool result)
{
	if (result)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
