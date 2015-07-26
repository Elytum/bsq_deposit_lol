/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>
#include <config.h>
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		prepare_fd_skip(char *str, int skip)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) <= 0)
		return (ft_map_error());
	str = ft_safe_malloc(skip + 1);
	if (read(fd, str, skip + 1) == -1)
	{
		write(1, READ_ERROR, sizeof(READ_ERROR));
		return (0);
	}
	free(str);
	return (fd);
}

char	*ft_safe_malloc(size_t length)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * (length + 1))))
	{
		write(1, MALLOC_ERROR, sizeof(MALLOC_ERROR) - 1);
		exit(0);
	}
	return (ptr);
}

void	put_file_path(char *str)
{
	write(1, PUT_FILE_INTRO, sizeof(PUT_FILE_INTRO) - 1);
	write(1, str, ft_strlen(str));
	write(1, PUT_FILE_END, sizeof(PUT_FILE_END) - 1);
}

void	generate_map(void)
{
	char	buffer[BUF_SIZE];
	int		ret;
	int		fd;

	if ((fd = open(MAP_PATH, O_WRONLY | O_CREAT | O_TRUNC)) <= 0)
		create_error(MAP_PATH);
	while ((ret = read(1, buffer, BUF_SIZE)))
		write(fd, buffer, ret);
	write(fd, buffer, ret);
	close(fd);
}
