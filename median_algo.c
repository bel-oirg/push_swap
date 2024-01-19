/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:00:14 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/19 23:50:10 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*lst_arr(t_stack_node *a)
{
	int	index;
	int	*arr;

	index = -1;
	arr = my_malloc(sizeof(int) * lst_len(a), 1);
	if (!arr)
		return (NULL);
	while (a)
	{
		arr[++index] = a->value;
		a = a->next;
	}
	return (arr);
}

static void	swap_arr(int *arr1, int *arr2)
{
	int	tmp;

	tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = tmp;
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size - 1 - j)
			if (arr[i] > arr[i + 1])
				swap_arr(&arr[i], &arr[i + 1]);
	}
}

int	find_median(t_stack_node *a)
{
	int	*arr;
	int	median;
	int	med_index;

	arr = lst_arr(a);
	if (!arr)
		return (INT_MAX);
	sort_arr(arr, lst_len(a));
	med_index = (int)(lst_len(a) / 2);
	median = arr[med_index];
	return (median);
}
