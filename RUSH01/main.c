/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:04:23 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 21:21:46 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	clues[16];
	int	n;
	int	*grid;

	if (argc != 2 || parse(argv[1], clues))
	{
		put_str("Error\n");
		return (1);
	}
	n = 4;
	grid = malloc(sizeof(int) * n * n);
	if (!grid)
	{
		put_str("Error\n");
		return (1);
	}
	init_grid(grid, n);
	if (solve(grid, clues, n, 0))
		print_grid(grid, n);
	else
		put_str("Error\n");
	free(grid);
	return (0);
}
