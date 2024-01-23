/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:27:06 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/22 05:14:19 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack_node	*find_highest(t_stack_node *a)
{
	t_stack_node	*highest_node;
	int				val;

	if (!a)
		return (NULL);
	val = INT_MIN;
	while (a)
	{
		if (a->value > val)
		{
			val = a->value;
			highest_node = a;
		}
		a = a->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*high;

	high = find_highest(*a);
	if ((*a) == high)
		ra(a, 0);
	else if ((*a)->next == high)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}

int	handle_5(t_stack_node **a, t_stack_node **b)
{
	int	size_len;

	size_len = lst_len(*a);
	while (size_len-- > 3)
	{
		init_nodes(*a, *b);
		finish_rot(a, find_smallest(*a), 'a');
		pb(b, a, 0);
	}
	return (1);
}
