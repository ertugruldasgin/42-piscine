/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 10:02:26 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/04 11:06:42 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;

	printf("selam");
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

void	ft_tail(void)
{
}
// malloc necessary amount of bytes
// traverse from tail to head while n--

// we should write last n bytes of a file when tail -c [num] [filename]
// write ==> file name <== when argc > 3
// print all file when tail [filename]

// tail -c [int] [filename...]
int	main(int argc, char *argv[])
{
	// if (argc < 4 || !(argv[1][0] == '-' && argv[1][1] == 'c'
	//		&& argv[1][2] == '\0'))
	//	return (1);
	ft_atoi(argv[2]);
	return (0);
}
