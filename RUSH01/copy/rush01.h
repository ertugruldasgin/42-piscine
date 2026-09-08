#ifndef RUSH_01_H
# define RUSH_01_H

void	put_char(char c);
void	put_str(char *str);
void	init_grid(int *grid, int n);
int		solve(int *grid, int *clues, int n, int pos);
void	print_grid(int *grid, int n);

#endif /* ifndef RUSH_01_H */
