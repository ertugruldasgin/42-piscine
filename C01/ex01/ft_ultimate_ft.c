/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 03:19:27 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/10 17:29:18 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int	n9;
	int	*n8;
	int	**n7;
	int	***n6;
	int	****n5;
	int	*****n4;
	int	******n3;
	int	*******n2;
	int	********n1;
	int	*********n0;

	n9 = 21;
	printf("%d\n", n9);
	n8 = &n9;
	n7 = &n8;
	n6 = &n7;
	n5 = &n6;
	n4 = &n5;
	n3 = &n4;
	n2 = &n3;
	n1 = &n2;
	n0 = &n1;
	ft_ultimate_ft(n0);
	printf("%d", n9);
}
