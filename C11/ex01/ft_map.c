/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:17:35 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 00:22:03 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	*head;

	res = malloc(sizeof(int) * length);
	if (!res)
		return (NULL);
	head = res;
	while (length--)
		*res++ = f(*tab++);
	return (head);
}
