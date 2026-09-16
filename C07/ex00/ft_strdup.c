/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 02:33:49 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/16 16:36:01 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*res;
	int		len;

	len = 0;
	while (src[len])
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	res = ptr;
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (res);
}

int	main(void)
{
	printf("%s", ft_strdup("hello world!"));
	return (0);
}
