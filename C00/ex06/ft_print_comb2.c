/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:22:13 by udasgin           #+#    #+#             */
/*   Updated: 2026/08/28 01:34:00 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_num(int n)
{
	char	c;

	c = n / 10 + '0';
	write(1, &c, 1);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_convert_num(i);
			write(1, " ", 1);
			ft_convert_num(j);
			if (!(i == 98 && j == 99))
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
