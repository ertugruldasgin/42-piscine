/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:36:23 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/16 13:20:28 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		is_valid_base(char *base);
int		ft_atoi_base(char *str, char *base);

int	num_len(long num, int base_len)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long	num;
	int		len;
	int		base_len;
	char	*res;

	base_len = ft_strlen(base);
	num = nbr;
	len = num_len(num, base_len);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = base[0];
	while (num)
	{
		res[--len] = base[num % base_len];
		num /= base_len;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}

int	main(void)
{
	printf("%s\n", ft_convert_base("ff", "0123456789abcdef", "01"));
	printf("%s\n", ft_convert_base("42", "0123456789", "01"));
	printf("%s\n", ft_convert_base("0", "0123456789", "01"));
	printf("%s\n", ft_convert_base("12z34", "0123456789", "0123456789"));
	printf("%s\n", ft_convert_base("1", "01", "0"));
	return (0);
}
