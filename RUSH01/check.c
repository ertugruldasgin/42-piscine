/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:09:12 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 20:48:35 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible(int *grid, int n, int start, int step)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	while (i < n)
	{
		if (grid[start + i * step] > max)
		{
			max = grid[start + i * step];
			seen++;
		}
		i++;
	}
	return (seen);
}

int	check_row(int *grid, int *clues, int n, int i)
{
	int	left;
	int	right;

	left = count_visible(grid, n, i * n, 1);
	right = count_visible(grid, n, i * n + n - 1, -1);
	if (left != clues[2 * n + i])
		return (0);
	if (right != clues[3 * n + i])
		return (0);
	return (1);
}

int	check_col(int *grid, int *clues, int n, int j)
{
	int	top;
	int	bottom;

	top = count_visible(grid, n, j, n);
	bottom = count_visible(grid, n, (n - 1) * n + j, -n);
	if (top != clues[j])
		return (0);
	if (bottom != clues[n + j])
		return (0);
	return (1);
}

int	check_pos(int *grid, int *clues, int n, int pos)
{
	int	i;
	int	j;

	i = pos / n;
	j = pos % n;
	if (j == n - 1 && !check_row(grid, clues, n, i))
		return (0);
	if (i == n - 1 && !check_col(grid, clues, n, j))
		return (0);
	return (1);
}
