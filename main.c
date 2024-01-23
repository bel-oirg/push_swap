/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:14:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/22 05:18:36 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_on_top(t_stack_node **a)
{
	t_stack_node	*smallx;

	smallx = find_smallest(*a);
	while (*a != smallx)
	{
		if (smallx->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

static void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				median;
	int				i;

	(lst_len(*a) == 5) && (handle_5(a, b));
	while (lst_len(*a) > 3)
	{
		i = 0;
		median = find_median(*a);
		(median == INT_MAX) && (write(2, ERR, 6), my_malloc(0, 0), 0);
		while (i < lst_len(*a))
		{
			if ((*a)->value < median)
				pb(b, a, 0);
			else
				(ra(a, 0));
			i++;
		}
	}
	tiny_sort(a);
	while (*b)
		(init_nodes(*a, *b), rotate_everything(a, b));
	set_current_position(*a);
	small_on_top(a);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				lst_size;
	int				index;

	a = NULL;
	b = NULL;
	index = 0;
	if (argc == 1)
		return (0);
	if (argc >= 2)
		argv = parsed(argv);
	if (init_stack(&a, argv))
		return (write(2, ERR, 6), my_malloc(0, 0), -1);
	lst_size = lst_len(a);
	if (!is_sorted(a))
		(lst_size == 2) && (sa(&a, 0), 0),
		(lst_size == 3) && (tiny_sort(&a), 0),
		(lst_size >= 4) && (push_swap(&a, &b), 0);
	my_malloc(0, 2);
}
