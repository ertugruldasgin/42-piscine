#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_str(char *str)
{
	while (*str)
		write(1, str, 1);
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
