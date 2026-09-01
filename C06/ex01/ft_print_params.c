/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 20:01:25 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/01 20:07:53 by udasgin          ###   ########.fr       */
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

	if (argc > 1)
	{
		i = 1;
		while (*argv[i])
		{
			ft_print_arg(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}
