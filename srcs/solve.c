/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
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
#include <stdlib.h>

int		put_first(int fd, char *buffer, int length, int solution)
{
	int		i;

	i = 0;
	while (i < solution)
	{
		if (read(fd, buffer, length + 1) != (length + 1))
		{
			write(1, READ_ERROR, sizeof(READ_ERROR) - 1);
			close(fd);
			return (-1);
		}
		write(1, buffer, length + 1);
		++i;
	}
	return (i);
}

int		put_middle(int fd, char *buffer, int length, int solution[5])
{
	int		j;

	j = 0;
	while (j < solution[5])
	{
		if (read(fd, buffer, length + 1) != length + 1)
		{
			write(1, READ_ERROR, sizeof(READ_ERROR) - 1);
			close(fd);
			return (-1);
		}
		ft_memset(buffer + solution[3], solution[2], solution[5]);
		write(1, buffer, length + 1);
		++j;
	}
	return (j);
}

void	put_end(int fd, char *buffer, int length, int i)
{
	while (i--)
	{
		if (read(fd, buffer, length + 1) != length + 1)
		{
			write(1, READ_ERROR, sizeof(READ_ERROR) - 1);
			return ;
		}
		write(1, buffer, length + 1);
	}
}

void	put_solution(int fd, int solution[5], int length, int nb)
{
	int		i;
	int		j;
	char	*buffer;

	if (fd == 0)
		return ;
	buffer = ft_safe_malloc(length);
	if ((i = put_first(fd, buffer, length, solution[4]) == -1) ||
		(j = put_middle(fd, buffer, length, solution)) == -1)
		return ;
	i += j;
	put_end(fd, buffer, length, nb - i);
	close(fd);
	free(buffer);
}

void	solve_map(char *path)
{
	int		nb;
	int		length;
	int		pattern[6];
	int		skip;

	if (VERBOSE)
		ft_tell_path(path);
	if (!get_intro(path, &nb, &skip, pattern) ||
		!get_length(path, &length, skip) ||
		!solve(prepare_fd_skip(path, skip), length, pattern, nb))
		return ;
	if (VERBOSE)
		ft_tell_solution(pattern + 3);
	put_solution(prepare_fd_skip(path, skip), pattern, length, nb);
}
