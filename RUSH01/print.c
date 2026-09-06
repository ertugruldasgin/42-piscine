/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:08:11 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 20:15:22 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		put_char(s[i]);
		i++;
	}
}

void	print_grid(int *grid, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			put_char(grid[i * n + j] + '0');
			if (j < n - 1)
				put_char(' ');
			j++;
		}
		put_char('\n');
		i++;
	}
}
