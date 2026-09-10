/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:04:33 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/10 17:43:16 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	*head;
	int	*tail;
	int	temp;

	head = tab;
	tail = tab + size - 1;
	while (head < tail)
	{
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}
}

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};
	int	i;

	ft_rev_int_tab(tab, 5);
	i = 0;
	while (i < 5)
	{
		printf("%d", tab[i]);
		i++;
	}
}
