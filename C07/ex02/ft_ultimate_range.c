/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:14:45 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/02 15:31:15 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*res;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	res = malloc(sizeof(int) * (max - min));
	if (!res)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	while (min < max)
		res[i++] = min++;
	*range = res;
	return (i);
}
