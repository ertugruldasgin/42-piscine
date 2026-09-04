/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 05:28:58 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/04 06:24:24 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 20480

unsigned int	ft_str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_err_msg(char *base, char *filename)
{
	char	*strerr;

	strerr = strerror(errno);
	write(2, base, ft_str_len(base));
	write(2, ": ", 2);
	write(2, filename, ft_str_len(filename));
	write(2, ": ", 2);
	write(2, strerr, ft_str_len(strerr));
	write(2, "\n", 1);
}

int	ft_read_fd(int fd)
{
	char	buf[BUFFER_SIZE];
	int		len;

	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		write(1, buf, len);
		len = read(fd, buf, BUFFER_SIZE);
	}
	return (len);
}

void	ft_cat(char *base, char *filename)
{
	int	fd;
	int	status;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_err_msg(base, filename);
		return ;
	}
	status = ft_read_fd(fd);
	if (status == -1)
		ft_err_msg(base, filename);
	close(fd);
}

int	main(int argc, char *argv[])
{
	char	*base;

	if (argc == 1)
		ft_read_fd(0);
	else if (argc > 1)
	{
		base = basename(argv[0]);
		++argv;
		while (*argv)
			ft_cat(base, *argv++);
	}
	return (0);
}
