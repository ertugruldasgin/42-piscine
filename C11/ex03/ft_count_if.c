/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:26:59 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 00:28:35 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;

	count = 0;
	while (length--)
	{
		if (f(*tab))
			count++;
		tab++;
	}
	return (count);
}
