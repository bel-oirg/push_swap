/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:55:21 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/22 00:31:05 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err_syntax(char *str)
{
	if (!(*str == '-' || *str == '+'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') && (str[1] < '0' || str[1] > '9'))
		return (1);
	while (*(++str))
		if (*str < '0' || *str > '9')
			return (1);
	return (0);
}

int	err_rep(t_stack_node *a, int num)
{
	t_stack_node	*current;
	int				val;

	if (!a)
		return (0);
	current = a;
	while (current)
	{
		val = current->value;
		if (val == num)
			return (1);
		current = current->next;
	}
	return (0);
}
