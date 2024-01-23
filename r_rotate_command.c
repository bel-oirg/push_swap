/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:06:59 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/22 03:18:53 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!stack || !*stack || lst_len(*stack) == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	(*stack)->next->prev = *stack;
}

void	rra(t_stack_node **a, int checker)
{
	r_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int checker)
{
	r_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, int checker)
{
	r_rotate(a);
	r_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
