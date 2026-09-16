/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:55:19 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/16 16:39:30 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int	main(void)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_range(32, 42);
	while (i < 10)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
