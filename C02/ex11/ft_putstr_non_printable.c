/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 08:31:45 by udasgin           #+#    #+#             */
/*   Updated: 2026/08/28 09:07:12 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	char			*hex;

	hex = "0123456789abcdef";
	while (*str)
	{
		c = *str;
		if (ft_is_printable(c))
			ft_putchar(c);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[c / 16]);
			ft_putchar(hex[c % 16]);
		}
		str++;
	}
}
