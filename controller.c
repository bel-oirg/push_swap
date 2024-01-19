/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:09:47 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/24 13:34:39 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_cheapest(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}

static void	rot_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap_b)
{
	while (*b != cheap_b && *a != cheap_b->target_node)
		rr(a, b, 0);
	set_current_position(*a);
	set_current_position(*b);
}

static void	r_rot_both(t_stack_node **a, t_stack_node **b, t_stack_node *ch_b)
{
	while (*b != ch_b && *a != ch_b->target_node)
		rrr(a, b, 0);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rot(t_stack_node **stack, t_stack_node *cheap_node, char stack_n)
{
	while (*stack != cheap_node)
	{
		if (cheap_node->above_median)
		{
			if (stack_n == 'a')
				ra(stack, 0);
			else
				rb(stack, 0);
		}
		else
		{
			if (stack_n == 'a')
				rra(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	rotate_everything(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_a;
	t_stack_node	*cheap_b;

	cheap_b = find_cheapest(*b);
	cheap_a = cheap_b->target_node;
	if (cheap_a->above_median && cheap_b->above_median)
		rot_both(a, b, cheap_b);
	else if (!(cheap_a->above_median) && !(cheap_b->above_median))
		r_rot_both(a, b, cheap_b);
	finish_rot(a, cheap_a, 'a');
	finish_rot(b, cheap_b, 'b');
	pa(a, b, 0);
}
