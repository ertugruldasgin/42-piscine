/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 00:58:17 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/07 01:45:03 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (sign * n);
}

void	ft_putnbr(int nb)
{
	char	a;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb / 10)
		{
			ft_putnbr(-(nb / 10));
		}
		a = -(nb % 10) + '0';
	}
	else
	{
		if (nb / 10)
		{
			ft_putnbr(nb / 10);
		}
		a = (nb % 10) + '0';
	}
	write(1, &a, 1);
}

int	get_op_index(char *op)
{
	int		i;
	char	*symbols;

	i = 0;
	symbols = "+-*/%";
	if (op[1] != '\0')
		return (-1);
	while (i < 5)
	{
		if (*op == symbols[i])
			return (i);
		i++;
	}
	return (-1);
}

int	apply_op(int op, int lval, int rval)
{
	int	(*ops[5])(int, int);

	ops[0] = &ft_add;
	ops[1] = &ft_sub;
	ops[2] = &ft_mul;
	ops[3] = &ft_div;
	ops[4] = &ft_mod;
	return (ops[op](lval, rval));
}

int	main(int argc, char *argv[])
{
	int	lval;
	int	rval;
	int	op;

	if (argc != 4)
		return (0);
	lval = ft_atoi(argv[1]);
	rval = ft_atoi(argv[3]);
	op = get_op_index(argv[2]);
	if (op == -1)
		ft_putnbr(0);
	else if (op == 3 && rval == 0)
		write(1, "Stop : division by zero", 23);
	else if (op == 4 && rval == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(apply_op(op, lval, rval));
	write(1, "\n", 1);
	return (0);
}
