/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 20:35:37 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/01 20:39:23 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_arg(char arg[])
{
	while (*arg)
	{
		write(1, arg, 1);
		arg++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		return (0);
	i = argc - 1;
	while (i > 1)
	{
		if (*argv[i])
		{
			ft_print_arg(argv[i]);
			write(1, "\n", 1);
			i--;
		}
	}
}
