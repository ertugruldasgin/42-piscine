/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 19:32:08 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 20:48:18 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_grid(int *grid, int n)
{
	int	i;

	i = 0;
	while (i < n * n)
	{
		grid[i] = 0;
		i++;
	}
}

int	is_safe(int *grid, int n, int pos, int val)
{
	int	i;
	int	row;
	int	col;

	row = pos / n;
	col = pos % n;
	i = 0;
	while (i < n)
	{
		if (grid[row * n + i] == val)
			return (0);
		if (grid[i * n + col] == val)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int *grid, int *clues, int n, int pos)
{
	int	val;

	if (pos == n * n)
		return (1);
	val = 1;
	while (val <= n)
	{
		if (is_safe(grid, n, pos, val))
		{
			grid[pos] = val;
			if (check_pos(grid, clues, n, pos))
			{
				if (solve(grid, clues, n, pos + 1))
					return (1);
			}
			grid[pos] = 0;
		}
		val++;
	}
	return (0);
}
