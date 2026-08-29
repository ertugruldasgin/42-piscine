/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:37:40 by udasgin           #+#    #+#             */
/*   Updated: 2026/08/29 18:49:21 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*temp_str;
	char	*temp_find;

	if (!*to_find)
		return (str);
	while (*str)
	{
		temp_str = str;
		temp_find = to_find;
		while (*str && *temp_find && *str == *temp_find)
		{
			str++;
			temp_find++;
		}
		if (!*temp_find)
			return (temp_str);
		str++;
	}
	return (0);
}
