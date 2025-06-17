/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:05:03 by akolupae          #+#    #+#             */
/*   Updated: 2025/06/17 18:18:32 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_putarr(int *arr, int nmem);
bool	ft_issorted(int *arr, int nmem);
void	ft_swap(int *a, int *b);
void	sa(int *arr, int nmem);

int	main(int argc, char **argv)
{
	char	command[4];
	int		arr[10];
	int		i;

	i = 0;
	ft_memset(arr, 0, (argc - 1) * sizeof(int));
	while (i < argc - 1 && i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_putarr(arr, argc - 1);
	ft_memset(command, 0, 4 * sizeof(char));
	read(0, command, 3);
	if (command[2] == '\n')
		command[2] = 0;
	if (ft_strncmp(command, "sa", 3) == 0)
		sa(arr, argc - 1);
	ft_putarr(arr, argc - 1);
	return (0);
}

void	sa(int *arr, int nmem)
{
	if (nmem > 1)
		ft_swap(&arr[0], &arr[1]);
}

int	ft_putarr(int *arr, int nmem)
{
	int	i;

	i = 0;
	while (i < nmem)
	{
		if (ft_printf("%d\n", arr[i]) == -1)
			return (-1);
		i++;
	}
	if (ft_issorted(arr, nmem))
		ft_putendl_fd("✅", 1);
	return (i);
}

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

void	ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
