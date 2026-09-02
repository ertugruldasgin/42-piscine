/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:55:19 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/02 15:12:08 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*head;
	int	*ptr;
	int	len;

	if (min >= max)
		return (NULL);
	len = max - min;
	head = malloc(sizeof(int) * len);
	if (!head)
		return (NULL);
	ptr = head;
	while (len--)
	{
		*ptr++ = min++;
	}
	return (head);
}
