/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:53:07 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/12 17:36:44 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*res;

	res = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}

int	main(void)
{
	char	dest[10];
	char	src[] = "Hello";
	char	*res;

	res = ft_strcpy(dest, src);
	printf("%s", res);
}
