#include <bsq.h>
#include <config.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

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
			test = analyse[i];
			if (test > length + solution[2] - i)
				test = length - i;
			if (test < solution[2])
			{
				++i;
				continue ;
			}
			x = i;
			while (x - i < test)
			{
				if (analyse[x++] < test)
					break ;
			}
			if (x - i == test)
			{
				solution[0] = i;
				solution[1] = y - test + 1;
				length += solution[2] - test;
				solution[2] = test;
			}
		}
		++i;
	}
}

static inline void	update_analyse(char *tmp, int *analyse,
					int length, int pattern[6])
{
	int			i;

	if (tmp[length] != '\n')
		map_error_exit();
	i = 0;
	while (i < length)
	{
		if (tmp[i] == pattern[0])
			analyse[i]++;
		else if (tmp[i] == pattern[1])
			analyse[i] = 0;
		else
			map_error_exit();
		++i;
	}
}

int					solve(int fd, int length, int pattern[6], int nb)
{
	char		*tmp;
	int			*analyse;
	int			i;

	if (fd == 0)
		return (0);
	pattern[3] = 0;
	pattern[4] = 0;
	pattern[5] = 0;
	tmp = ft_safe_malloc(length + 1);
	if (!(analyse = (int *)malloc(sizeof(int) * length)))
	{
		write(1, MALLOC_ERROR, sizeof(MALLOC_ERROR));
		exit(0);
	}
	ft_memset((char *)analyse, 0, length * 4);
	i = 0;
	while (i < nb)
	{
		if (read(fd, tmp, length + 1) < length + 1)
			map_error_exit();
		update_analyse(tmp, analyse, length, pattern);
		deduce_analyse(analyse, length, pattern + 3, i);
		++i;
	}
	free(tmp);
	free(analyse);
	if (read(fd, tmp, 1) == 1)
		map_error_exit();
	close(fd);
	return (1);
}