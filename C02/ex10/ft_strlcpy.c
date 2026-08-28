/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 08:02:47 by udasgin           #+#    #+#             */
/*   Updated: 2026/08/28 08:27:55 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;
	char			*temp;

	temp = src;
	len = 0;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (size > 0)
	{
		i = 0;
		while (src[i] && size - 1 > i)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
