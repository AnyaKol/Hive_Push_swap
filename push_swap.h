/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:28:04 by akolupae          #+#    #+#             */
/*   Updated: 2025/07/11 09:11:24 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*values;
	int	nmem;
}	t_stack;

typedef struct s_cost
{
	int	cost;
	int	a;
	int	b;
}	t_cost;

void	sort_stack(t_stack *a);
void	leave_chain(t_stack *a, t_stack *b);
void	fill_gaps(t_stack *a, t_stack *b);
void	rotate_to_start(t_stack *a);
void	rotate_stack(t_cost index, t_stack *a, t_stack *b);
void	apply_command(char *command, t_stack *a, t_stack *b);
t_stack	*create_stack(int nmem);
void	free_stack(t_stack *stack);
int		index_in_stack(int num, t_stack *stack);
int		print_error(void);

void	print_stack(t_stack *stack);

#endif
