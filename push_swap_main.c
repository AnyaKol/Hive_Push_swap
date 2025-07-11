/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/11 11:05:41 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_arg(char *arg);
static bool	check_repeat(t_stack stack);

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;

	if (argc <= 2)
		return (0);
	a = create_stack(argc - 1);
	if (a == NULL)
		return (0);
	a->nmem = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i]))
			return (print_error());
		a->values[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!check_repeat(*a))
		return (print_error());
	sort_stack(a);
	if (ft_issorted(*a))
		ft_printf("✅\n");
	ft_printf("Commands: %i\n", apply_command("", NULL, NULL));
	free_stack(a);
	return (0);
}

static bool	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	if (ft_atoi(arg) == 0 && i > 2)
		return (false);
	return (true);
}

static bool	check_repeat(t_stack stack)
{
	int	i;
	int	j;
	int	current_num;

	i = 0;
	while (i < stack.nmem - 1)
	{
		current_num = stack.values[i];
		j = i + 1;
			while (j < stack.nmem)
			{
				if (current_num == stack.values[j])
					return (false);
				j++;
			}
		i++;
	}
	return (true);
}
