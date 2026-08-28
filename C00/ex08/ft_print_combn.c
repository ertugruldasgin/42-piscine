/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 01:42:35 by udasgin           #+#    #+#             */
/*   Updated: 2026/08/28 02:44:36 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_combn(int *val, int pos, int len, int min_val)
{
	int		d;
	char	c;

	if (pos == len)
	{
		d = 0;
		while (d < len)
		{
			c = val[d] + '0';
			write(1, &c, 1);
			d++;
		}
		if (val[0] != 10 - len)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	d = min_val;
	while (d < 10)
	{
		val[pos] = d;
		ft_combn(val, pos + 1, len, d + 1);
		d++;
	}
}

void	ft_print_combn(int n)
{
	int	digits[10];

	ft_combn(digits, 0, n, 0);
}
