/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:27:48 by akolupae          #+#    #+#             */
/*   Updated: 2025/06/17 11:54:52 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void);

void	push_swap(...)
{
	va_list args;
	char	*result;

	result = NULL;
	va_start(args);
	va_arg(args, int);
	va_end(args);
	if (ft_printf("%s", result) == -1)
		print_error();
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}
