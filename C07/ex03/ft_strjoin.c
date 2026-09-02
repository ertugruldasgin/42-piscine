/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:14 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/02 16:05:06 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_total_len(int size, char **str, char *sep)
{
	int	total;

	total = ft_strlen(sep) * (size - 1);
	while (size--)
		total += ft_strlen(*str++);
	return (total);
}

char	*ft_append_str(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	char	*ptr;

	if (size <= 0)
	{
		res = malloc(1);
		if (res)
			*res = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (!res)
		return (NULL);
	ptr = res;
	i = 0;
	while (i < size)
	{
		ptr = ft_append_str(ptr, strs[i]);
		if (++i < size)
			ptr = ft_append_str(ptr, sep);
	}
	*ptr = '\0';
	return (res);
}
