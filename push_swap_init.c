/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 05:42:32 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/19 20:29:42 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	index;
	int	median;

	if (!stack)
		return ;
	index = 0;
	median = lst_len(stack) / 2;
	while (stack)
	{
		stack->current_position = index;
		if (index <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		index++;
	}
}

void	set_push_price(t_stack_node *a, t_stack_node *b)
{
	int	size_b;
	int	size_a;

	if (!a || !b)
		return ;
	size_b = lst_len(b);
	size_a = lst_len(a);
	while (b)
	{
		if (b->above_median)
			b->push_price = b->current_position;
		else
			b->push_price = size_b - b->current_position;
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += size_a - b->target_node->current_position;
		b = b->next;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	int				smallest_big;
	t_stack_node	*target_n;
	t_stack_node	*tmp_a;

	while (b)
	{
		tmp_a = a;
		smallest_big = INT_MAX;
		while (tmp_a)
		{
			if (b->value < tmp_a->value && tmp_a->value < smallest_big)
			{
				smallest_big = tmp_a->value;
				target_n = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (smallest_big != INT_MAX)
			b->target_node = target_n;
		else
			b->target_node = find_smallest(a);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *a)
{
	t_stack_node	*cheapest_node;
	int				val;

	if (!a)
		return ;
	val = INT_MAX;
	while (a)
	{
		if (a->push_price < val)
		{
			cheapest_node = a;
			val = a->push_price;
		}
		a = a->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_push_price(a, b);
	set_cheapest(b);
}
