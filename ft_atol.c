/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:59:02 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/30 21:44:26 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *(str++) - '0';
		if ((num * sign > INT_MAX) || (num * sign < INT_MIN))
			return (LONG_MAX);
	}
	return (sign * num);
}
