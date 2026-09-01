/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 20:39:49 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/02 02:06:44 by udasgin          ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_arg_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_print_all_args(char **args)
{
	args++;
	while (**args)
	{
		ft_print_arg(*args);
		write(1, "\n", 1);
		args++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			j = i + 1;
			while (j < argc)
			{
				if (ft_strcmp(argv[i], argv[j]) > 0)
					ft_arg_swap(&argv[i], &argv[j]);
				j++;
			}
			i++;
		}
		ft_print_all_args(argv);
	}
	return (0);
}
