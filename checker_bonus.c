/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:46:49 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/20 04:14:04 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int atoc1(char *command, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(command, "ra\n"))
		(lst_len(*a) >= 2) && (ra(a, 1), 0);
	else if (!ft_strcmp(command, "rb\n"))
		(lst_len(*b) >= 2) && (rb(b, 1), 0);
	else if (!ft_strcmp(command, "rra\n"))
		(lst_len(*a) >= 2) && (rra(a, 1), 0);
	else if (!ft_strcmp(command, "pa\n"))
		(lst_len(*b) >= 1) && (pa(a, b, 1), 0);
	else if (!ft_strcmp(command, "pb\n"))
		(lst_len(*a) >= 1) && (pb(b, a, 1), 0);
	else if (!ft_strcmp(command, "sa\n"))
		(lst_len(*a) >= 2) && (sa(a, 1), 0);
	else
		return (0);
	return (-1);
}

static int	atoc2(char *command, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(command, "sb\n"))
		(lst_len(*b) >= 2) && (sb(b, 1), 0);
	else if (!ft_strcmp(command, "rrr\n"))
		((lst_len(*a) >= 2) && (lst_len(*b) >= 2) && (rrr(a, b, 1), 0));
	else if (!ft_strcmp(command, "rr\n"))
		((lst_len(*a) >= 2) && (lst_len(*b) >= 2) && (rr(a, b, 1), 0));
	else if (!ft_strcmp(command, "rrb\n"))
		(lst_len(*b) >= 2) && (rrb(b, 1), 0);
	else if (!ft_strcmp(command, "ss\n"))
		(lst_len(*a) >= 2) && (lst_len(*b) >= 2) && (ss(a, b, 1), 0);
	else
		return (0);
	return (-1);
}

static int	checker_controller(char *command, t_stack_node **a, t_stack_node **b)
{
	if ((!atoc1(command, a, b)) && (!atoc2(command, a, b)))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*command;

	if (argc == 1)
		return (0);
	if (argc >= 2)
		argv = parsed(argv, argc);
	if (init_stack(&a, argv) == 1)
		return (write(2, "Error\n", 6), my_malloc(0, 0), 0);
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (checker_controller(command, &a, &b))
			(free(command), write(2, ERR, 6), my_malloc(0, 0));
		free(command);
	}
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	my_malloc(0, 2);
}
