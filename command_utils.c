/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:18:43 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/31 03:42:54 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(t_stack_node *stack)
{
	if (!stack)
		return (0);
	return (1 + lst_len(stack->next));
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	t_stack_node	*last;

	last = stack;
	if (!last)
		return (NULL);
	while ((last)->next)
		last = last->next;
	return (last);
}
