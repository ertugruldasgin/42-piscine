/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 03:41:47 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/04 04:26:30 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void	ft_display_file(char *filename)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		write(1, buf, len);
		len = read(fd, buf, BUFFER_SIZE);
	}
	if (len < 0)
		write(2, "Cannot read file.\n", 18);
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		ft_display_file(argv[1]);
	return (0);
}
