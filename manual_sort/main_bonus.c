/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/06/19 16:35:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_putarrs(int *arra, int *arrb, int nmem);

int	main(int argc, char **argv)
{
	char	command[4];
	int		arra[10];
	int		arrb[10];
	int		i;
	int		nmem;

	if (argc < 3)
		return (0);
	nmem = argc - 1;
	ft_memset(arra, 0, (nmem) * sizeof(int));
	ft_memset(arrb, 0, (nmem) * sizeof(int));
	i = 0;
	while (i < argc - 1 && i < nmem)
	{
		arra[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	ft_putarrs(arra, arrb, nmem);
	while (!ft_issorted(arra, nmem) || !ft_isempty(arrb, nmem))
	{
		ft_memset(command, 0, 4 * sizeof(char));
		read(0, command, 4);
		if (command[2] == '\n')
			command[2] = 0;
		i += apply_command(command, arra, arrb, nmem);
		ft_putarrs(arra, arrb, nmem);
	}
	ft_printf("Commands: %d\n", i);
	return (0);
}

int	ft_putarrs(int *arra, int *arrb, int nmem)
{
	int	i;

	ft_printf("a  b\n");
	i = 0;
	while (i < nmem)
	{
		if (ft_printf("% d % d\n", arra[i], arrb[i]) == -1)
			return (-1);
		i++;
	}
	if (ft_issorted(arra, nmem))
		ft_putstr_fd("✅ ", 1);
	else
		ft_putstr_fd("❌ ", 1);
	if (ft_isempty(arrb, nmem))
		ft_putendl_fd("✅\n", 1);
	else
		ft_putendl_fd("❌\n", 1);
	return (i);
}




