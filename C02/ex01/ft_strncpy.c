/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:59:34 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/12 17:40:21 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*res;

	res = dest;
	while (*src && n > 0)
	{
		*dest++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}
	return (res);
}

int	main(void)
{
	char			dest[8] = "XXXXXXXX";
	char			src[] = "Hello";
	unsigned int	n;
	char			*res;

	n = 3;
	res = ft_strncpy(dest, src, n);
	printf("%s", res);
}
