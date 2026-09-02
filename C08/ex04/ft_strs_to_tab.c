/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:25:13 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/02 20:59:08 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strstr(char *str)
{
	char	*dest;
	char	*res;

	dest = malloc(sizeof(char) * (ft_str_len(str) + 1));
	if (!dest)
		return (0);
	res = dest;
	while (*str)
		*dest++ = *str++;
	*dest = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	res = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_str_len(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strstr(av[i]);
		i++;
	}
	res[i].str = NULL;
	return (res);
}
