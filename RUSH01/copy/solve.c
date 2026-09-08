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
