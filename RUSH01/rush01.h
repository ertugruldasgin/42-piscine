/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:36:53 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 21:07:32 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

int		parse(char *s, int *clues);
int		count_visible(int *grid, int n, int start, int step);
int		check_row(int *grid, int *clues, int n, int i);
int		check_col(int *grid, int *clues, int n, int j);
int		check_pos(int *grid, int *clues, int n, int pos);
int		solve(int *grid, int *clues, int n, int pos);
void	init_grid(int *grid, int n);
int		is_safe(int *grid, int n, int pos, int val);
void	print_grid(int *grid, int n);
void	put_str(char *s);
void	put_char(char c);

#endif
