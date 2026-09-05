/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:29:19 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/06 00:38:49 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	up;
	int	down;
	int	cmp;

	up = 0;
	down = 0;
	while (--length > 0)
	{
		cmp = f(*tab, *(tab + 1));
		if (cmp > 0)
			up = 1;
		else if (cmp < 0)
			down = 1;
		tab++;
	}
	return (!(up && down));
}
