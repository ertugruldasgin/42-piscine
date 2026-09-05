/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 10:02:26 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/05 21:19:06 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdlib.h>
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

int	ft_atoi(char *str)
{
	int	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

void	ft_write_header(char *filename)
{
	write(1, "==> ", 4);
	write(1, filename, ft_str_len(filename));
	write(1, " <==", 4);
	write(1, "\n", 1);
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

void	*ft_memcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_read(int fd, int bytes)
{
	char	buf[BUFFER_SIZE];
	char	*res;
	int		filled;
	int		len;
	int		shift;

	if (bytes == 0)
		return (0);
	res = malloc(sizeof(char) * bytes);
	if (!res)
		return (-1);
	filled = 0;
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		if (len >= bytes)
		{
			ft_memcpy(res, buf + (len - bytes), bytes);
			filled = bytes;
		}
		else
		{
			if (filled + len > bytes)
			{
				shift = filled + len - bytes;
				ft_memcpy(res, res + shift, filled - shift);
				filled -= shift;
			}
			ft_memcpy(res + filled, buf, len);
			filled += len;
		}
		len = read(fd, buf, BUFFER_SIZE);
	}
	write(1, res, filled);
	free(res);
	return (len);
}

void	ft_tail(char *base, int bytes, char *filename, int show_header)
{
	int	fd;
	int	status;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_err_msg(base, filename);
		return ;
	}
	if (show_header)
		ft_write_header(filename);
	status = ft_read(fd, bytes);
	if (status == -1)
		ft_err_msg(base, filename);
	close(fd);
}

int	main(int argc, char *argv[])
{
	char	*base;
	int		bytes;
	int		multi;

	if (argc < 4 || !(argv[1][0] == '-' && argv[1][1] == 'c'
			&& argv[1][2] == '\0'))
		return (1);
	base = basename(argv[0]);
	bytes = ft_atoi(argv[2]);
	multi = (argc - 3) > 1;
	argv += 3;
	while (*argv)
		ft_tail(base, bytes, *argv++, multi);
	return (0);
}
