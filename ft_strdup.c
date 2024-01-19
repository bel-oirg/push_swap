/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:12:25 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/19 18:13:20 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	len_s1;
	int		index;

	len_s1 = ft_strlen(s1);
	str = my_malloc((len_s1 + 1) * (sizeof(char)), 1);
	if (!str)
		return (NULL);
	index = -1;
	while (s1[++index])
		str[index] = s1[index];
	str[index] = 0;
	return (str);
}
