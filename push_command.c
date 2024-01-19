/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:42:46 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/24 13:15:51 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*to_push;

	if (!src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (*dest)
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
	else
	{
		*dest = to_push;
		to_push->next = NULL;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, int checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, int checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
