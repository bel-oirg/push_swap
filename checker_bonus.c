/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:46:49 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/23 02:05:10 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	atoc1(char *command, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(command, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(command, "pa\n"))
		pa(a, b, 1);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, 1);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, 1);
	else
		return (0);
	return (-1);
}

static int	atoc2(char *command, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(command, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(command, "rrr\n"))
		(rra(a, 1), (rrb(b, 1)));
	else if (!ft_strcmp(command, "rr\n"))
		(ra(a, 1), (rb(b, 1)));
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(command, "ss\n"))
		(sa(a, 1), (sb(b, 1)));
	else
		return (0);
	return (-1);
}

static int	controller(char *command, t_stack_node **a, t_stack_node **b)
{
	if ((!atoc1(command, a, b)) && (!atoc2(command, a, b)))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;
	char			*command;

	if (argc == 1)
		return (0);
	(argc >= 2) && (argv = parsed(argv), 0);
	if (init_stack(&a, argv) == 1)
		return (write(2, ERR, 6), my_malloc(0, 0), 0);
	len = lst_len(a);
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (controller(command, &a, &b))
			(free(command), write(2, ERR, 6), my_malloc(0, 0));
		free(command);
	}
	if (lst_len(a) == len && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	my_malloc(0, 2);
}
