/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:46:49 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/19 23:59:04 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	atoc(char *command, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(command, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(command, "pa\n"))
		pa(a, b, 1);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, 1);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, 1);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, 1);
	else
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
	if (init_stack(&a, argv))
		return (write(2, "Error\n", 6), my_malloc(0, 0), 0);
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (atoc(command, &a, &b))
			(free(command), write(2, ERR, 6), my_malloc(0, 0));
		free(command);
	}
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	my_malloc(0, 2);
}
