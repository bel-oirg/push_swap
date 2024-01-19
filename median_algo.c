/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:00:14 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/19 20:06:44 by bel-oirg         ###   ########.fr       */
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

static int	semi_sort(int *arr, int l_val, int r_val)
{
	int	i;
	int	j;
	int	piv;

	i = l_val;
	j = l_val;
	piv = arr[r_val];
	while (j < r_val)
	{
		if (arr[j] <= piv)
		{
			swap_arr(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap_arr(&arr[i], &arr[j]); //why this ?
	return (i);
}

static void	sorted(int *arr, int l_val, int r_val)
{
	int	next_piv;

	if (l_val < r_val)
	{
		next_piv = semi_sort(arr, l_val, r_val);
		sorted(arr, l_val, next_piv - 1);
		sorted(arr, next_piv + 1, r_val);
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
	sorted(arr, 0, lst_len(a) - 1);
	med_index = (int)(lst_len(a) / 2);
	median = arr[med_index];
	return (median);
}
