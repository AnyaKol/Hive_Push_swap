/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:16:18 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/15 19:00:13 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(void)
{
	int	fd;

	fd = open("check.sh");
	ft_printf("Hello");
	ft_printf("Line 1: %s", get_next_line(fd));
	ft_printf("Line 2: %s", get_next_line(fd));
	close(fd);
	return (0);
}
