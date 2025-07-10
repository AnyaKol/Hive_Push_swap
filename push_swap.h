/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:28:04 by akolupae          #+#    #+#             */
/*   Updated: 2025/06/19 16:26:36 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*values;
	int		nmem;
}	t_stack;

void	sort_stack(t_stack *a);
void	apply_command(char *command, t_stack *a, t_stack *b);
t_stack	*create_stack(int nmem);
void	free_stack(t_stack *stack);
int		print_error(void);

bool	ft_issorted(int *arr, int nmem);
bool	ft_isempty(int *arr, int nmem);
void	print_stack(t_stack *stack);

#endif
