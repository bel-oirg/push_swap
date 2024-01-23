/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:09:49 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/22 05:18:05 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **a, int num)
{
	t_stack_node	*node;
	t_stack_node	*last;

	(!a) && (write(2, ERR, 6), my_malloc(0, 0));
	node = my_malloc(sizeof(t_stack_node), 1);
	(!node) && (write(2, ERR, 6), my_malloc(0, 0));
	node->value = num;
	node->next = NULL;
	if (!*a)
	{
		node->prev = NULL;
		*a = node;
	}
	else
	{
		last = find_last_node(*a);
		last->next = node;
		node->prev = last;
	}
}

t_stack_node	*find_smallest(t_stack_node *a)
{
	t_stack_node	*smallest_node;
	int				smallest;

	if (!a)
		return (NULL);
	if (lst_len(a) == 1)
		return (a);
	smallest = INT_MAX;
	while (a)
	{
		if (smallest > a->value)
		{
			smallest_node = a;
			smallest = a->value;
		}
		a = a->next;
	}
	return (smallest_node);
}

int	init_stack(t_stack_node **a, char *argv[])
{
	long	lnum;
	int		i;

	if (!a)
		return (0);
	i = -1;
	while (argv[++i])
	{
		if (err_syntax(argv[i]))
			return (1);
		lnum = ft_atol(argv[i]);
		if (lnum == LONG_MAX)
			return (1);
		if (i > 0 && err_rep(*a, (int)lnum))
			return (1);
		append_node(a, (int)lnum);
	}
	return (0);
}

char	**parsed(char *argv[])
{
	char	*spaced_args;
	char	**micro_args;
	int		index;
	int		spaced_index;
	int		micro_index;

	index = 0;
	spaced_index = -1;
	spaced_args = NULL;
	while (argv[++index])
	{
		micro_index = -1;
		micro_args = ft_split(argv[index], ' ');
		(!micro_args[0]) && (write(2, ERR, 6), my_malloc(0, 0));
		while (micro_args[++micro_index])
			spaced_args = ft_strjoin(ft_strjoin(spaced_args, " "),
					micro_args[micro_index]);
	}
	return (ft_split(spaced_args, ' '));
}
