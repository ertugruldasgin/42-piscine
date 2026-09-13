/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:48:10 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/14 02:20:57 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	to_base_format(long num, char *base)
{
	long	len;

	len = ft_strlen(base);
	if (num >= len)
		to_base_format(num / len, base);
	write(1, &base[num % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;

	num = nbr;
	if (!is_valid_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	to_base_format(num, base);
}
