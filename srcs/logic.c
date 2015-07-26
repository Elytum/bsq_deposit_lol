/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
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

static inline int	deduce_solution(int solution[3], int i, int y, int test)
{
	int	ret;

	ret = test - solution[2];
	solution[0] = i;
	solution[1] = y - test + 1;
	solution[2] = test;
	return (ret);
}

static inline void	deduce_analyse(int *analyse,
					int length, int solution[3], int y)
{
	int			i;
	int			x;
	int			test;

	length -= solution[2];
	i = 0;
	while (i < length)
	{
		if (analyse[i] > solution[2])
		{
			if ((test = analyse[i]) > length + solution[2] - i)
				test = length - i;
			if (test < solution[2] && ++i)
				continue ;
			x = i;
			while (x - i < test && analyse[x] >= test)
				++x;
			if (x - i == test)
				length -= deduce_solution(solution, i, y, test);
		}
		++i;
	}
}

static inline int	update_analyse(char *tmp, int *analyse,
					int length, int pattern[6])
{
	int			i;

	if (tmp[length] != '\n')
		return (0);
	i = 0;
	while (i < length)
	{
		if (tmp[i] == pattern[0])
			analyse[i]++;
		else if (tmp[i] == pattern[1])
			analyse[i] = 0;
		else
			return (0);
		++i;
	}
	return (1);
}

void				solve_init(int pattern[6], char **tmp,
							int **analyse, int length)
{
	pattern[3] = 0;
	pattern[4] = 0;
	pattern[5] = 0;
	*tmp = (char *)malloc(sizeof(char) * (length + 1));
	if (!(*analyse = (int *)malloc(sizeof(int) * length)))
	{
		write(1, MALLOC_ERROR, sizeof(MALLOC_ERROR));
		exit(0);
	}
	ft_memset((char *)*analyse, 0, length * 4);
}

int					solve(int fd, int length, int pattern[6], int nb)
{
	char		*tmp;
	int			*analyse;
	int			i;

	if (fd == 0)
		return (0);
	solve_init(pattern, &tmp, &analyse, length);
	i = 0;
	while (i < nb)
	{
		if ((read(fd, tmp, length + 1) < length + 1) ||
			!(update_analyse(tmp, analyse, length, pattern)))
			return (solve_error_loop(fd, tmp, analyse));
		deduce_analyse(analyse, length, pattern + 3, i++);
	}
	free(analyse);
	if (read(fd, tmp, 1) == 1)
	{
		close(fd);
		return (ft_map_error());
	}
	free(tmp);
	close(fd);
	return (1);
}
