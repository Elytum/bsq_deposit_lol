#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

#define WRONG_USAGE_BEGIN "Wrong usage, should be: \""
#define WRONG_USAGE_END " <map_path>\"\n"

#define MALLOC_ERROR "malloc error\n"
#define READ_ERROR "read error\n"
#define MAP_ERROR "map error\n"
#define OPEN_ERROR_INTRO "Can't open file \""
#define OPEN_ERROR_END "\", exiting.\n"

#include <stdio.h>
#define VERBOSE 1

#define MAP_PATH_BEGIN "Opening map \""
#define MAP_PATH_END "\".\n"
#define MAP_INTRO_BEGIN "The size of the first line is "
#define MAP_INTRO_END ".\n"
#define MAP_INTRO_2_BEGIN "There is "
#define MAP_INTRO_2_MIDDLE_SING " line and the pattern is ["
#define MAP_INTRO_2_MIDDLE_MULT " lines and the pattern is ["
#define MAP_INTRO_2_END "].\n"
#define MAP_LENGTH_BEGIN "The size of every line should be \""
#define MAP_LENGTH_END "\".\n"
#define SOLUTION_INTRO "The biggest square have a size of "
#define SOLUTION_MIDDLE " and is starting in ["
#define SOLUTION_END "].\n"

#define	BUF_SIZE 1024

char		*ft_safe_malloc(size_t length)
{
	char		*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * (length + 1))))
	{
		write(1, MALLOC_ERROR, sizeof(MALLOC_ERROR) - 1);
		exit(0);
	}
	return (ptr);
}

void		ft_memset(char *str, char c, size_t len)
{
	while (len--)
		*str++ = c;
}

void		map_error_exit(void)
{
	write(1, MAP_ERROR, sizeof(MAP_ERROR) - 1);
	exit(0);
}

size_t		ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

void		ft_putnbr(int nb)
{
	char		buffer[11];
	char		*ptr;
	int			negatif;

	if (nb == -2147483648)
		write(1, "–2147483648", sizeof("–2147483648"));
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		ptr = buffer + sizeof(buffer) - 1;
		if (nb < 0)
		{
			negatif = 1;
			nb = -nb;
		}
		else
			negatif = 0;
		while (nb > 0)
		{
			*ptr-- = nb % 10 + '0';
			nb /= 10;
		}
		if (negatif)
			*ptr-- = '-';
		write(1, ptr + 1, sizeof(buffer) - (long)ptr + (long)buffer - 1);
	}
}

// -42 / 42 / +42 / 42a/ 42a

int			ft_atoi(const char *str)
{
	int			negatif;
	int			val;

	if (*str == '-')
	{
		str++;
		negatif = 1;
	}
	else
	{
		if (*str == '+')
			str++;
		negatif = 0;
	}
	val = 0;
	while (*str >= '0' && *str <= '9')
		val = val * 10 + (*str++) - '0';
	return ((negatif) ? -val : val);
}

char		*ft_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char		*ft_strnchr(const char *str, char c, int n)
{
	while (*str && n--)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

void		ft_open_error(const char *str)
{
	write(1, OPEN_ERROR_INTRO, sizeof(OPEN_ERROR_INTRO));
	write(1, str, ft_strlen(str));
	write(1, OPEN_ERROR_END, sizeof(OPEN_ERROR_END));
	exit(1);
}

void		ft_tell_path(const char *str)
{
	write(1, MAP_PATH_BEGIN, sizeof(MAP_PATH_BEGIN) - 1);
	write(1, str, ft_strlen(str));
	write(1, MAP_PATH_END, sizeof(MAP_PATH_END) - 1);
}

void		ft_tell_intro(int nb)
{
	write(1, MAP_INTRO_BEGIN, sizeof(MAP_INTRO_BEGIN) - 1);
	ft_putnbr(nb);
	write(1, MAP_INTRO_END, sizeof(MAP_INTRO_END) - 1);
}

void		ft_tell_intro_2(int nb, int pattern[6])
{
	char		buffer[11];

	write(1, MAP_INTRO_2_BEGIN, sizeof(MAP_INTRO_2_BEGIN) - 1);
	ft_putnbr(nb);
	if (nb > 1)
		write(1, MAP_INTRO_2_MIDDLE_MULT, sizeof(MAP_INTRO_2_MIDDLE_MULT) - 1);
	else
		write(1, MAP_INTRO_2_MIDDLE_SING, sizeof(MAP_INTRO_2_MIDDLE_SING) - 1);
	buffer[0] = '\'';
	buffer[1] = pattern[0];
	buffer[2] = '\'';
	buffer[3] = ',';
	buffer[4] = '\'';
	buffer[5] = pattern[1];
	buffer[6] = '\'';
	buffer[7] = ',';
	buffer[8] = '\'';
	buffer[9] = pattern[2];
	buffer[10] = '\'';
	write(1, buffer, sizeof(buffer));
	write(1, MAP_INTRO_2_END, sizeof(MAP_INTRO_2_END) - 1);
}

void		ft_tell_length(int nb)
{
	write(1, MAP_LENGTH_BEGIN, sizeof(MAP_LENGTH_BEGIN) - 1);
	ft_putnbr(nb);
	write(1, MAP_LENGTH_END, sizeof(MAP_LENGTH_END) - 1);
}

void		ft_tell_solution(int solution[3])
{
	write(1, SOLUTION_INTRO, sizeof(SOLUTION_INTRO));
	ft_putnbr(solution[2]);
	write(1, SOLUTION_MIDDLE, sizeof(SOLUTION_MIDDLE));
	ft_putnbr(solution[0]);
	write(1, ", ", sizeof(", "));
	ft_putnbr(solution[1]);
	write(1, SOLUTION_END, sizeof(SOLUTION_END));
}

int		check_provided_path(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, WRONG_USAGE_BEGIN, sizeof(WRONG_USAGE_BEGIN) - 1);
		write(1, av[0], ft_strlen(av[0]));
		write(1, WRONG_USAGE_END, sizeof(WRONG_USAGE_END) - 1);
		return (0);
	}
	if (VERBOSE)
		ft_tell_path(av[1]);
	return (1);
}


void		get_intro_2(const char *str, int *nb, int skip, int pattern[6])
{
	char	*buffer;
	int 	fd;

	if (skip <= 3)
		map_error_exit();
	buffer = ft_safe_malloc(skip);
	if ((fd = open(str, O_RDONLY)) <= 0)
		ft_open_error(str);
	if ((read(fd, buffer, skip)) == -1)
		write(1, READ_ERROR, sizeof(READ_ERROR)), exit(0);
	close(fd);
	pattern[0] = buffer[skip - 3];
	pattern[1] = buffer[skip - 2];
	pattern[2] = buffer[skip - 1];
	buffer[skip - 3] = '\0';
	*nb = ft_atoi(buffer);
	free(buffer);
	if (VERBOSE)
		ft_tell_intro_2(*nb, pattern);
}

void		get_intro(const char *str, int *nb, int *skip, int pattern[6])
{
	int		fd;
	int		ret;
	char	*ptr;
	char	buffer[BUF_SIZE];

	if ((fd = open(str, O_RDONLY)) <= 0)
		ft_open_error(str);
	*skip = 0;
	ptr = NULL;
	while ((ret = read(fd, buffer, BUF_SIZE)) == BUF_SIZE)
	{
		if ((ptr = ft_strnchr(buffer, '\n', BUF_SIZE)))
			break;
		*skip += BUF_SIZE;
	}
	if (ptr || (ptr = ft_strnchr(buffer, '\n', BUF_SIZE)))
		*skip += ptr - buffer;
	else
		*skip += ret;
	if (VERBOSE)
		ft_tell_intro(*skip);
	close(fd);
	get_intro_2(str, nb, *skip, pattern);
}

int			prepare_fd_skip(char *str, int skip)
{
	char	*tmp;
	int		fd;

	if ((fd = open(str, O_RDONLY)) <= 0)
		ft_open_error(str);
	str = ft_safe_malloc(skip + 1);
	if (read(fd, str, skip + 1) == -1)
	{
		write(1, READ_ERROR, sizeof(READ_ERROR));
		exit(0);
	}
	free(str);
	return (fd);
}

void		get_length(char *str, int *length, int skip)
{
	int 	fd;
	int		ret;
	char	buffer[BUF_SIZE];
	char	*ptr;

	fd = prepare_fd_skip(str, skip);
	*length = 0;
	ptr = NULL;
	while ((ret = read(fd, buffer, BUF_SIZE)) == BUF_SIZE)
	{
		if ((ptr = ft_strnchr(buffer, '\n', BUF_SIZE)))
			break;
		*length += BUF_SIZE;
	}
	close(fd);
	if (ptr || (ptr = ft_strnchr(buffer, '\n', BUF_SIZE)))
		*length += ptr - buffer;
	else
		*length += ret;
	if (VERBOSE)
		ft_tell_length(*length);
}

void		update_analyse(char *tmp, int *analyse, int length, int pattern[6])
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
//990949199509699397999199999999999999
void		ft_put_analyse(int *analyse, int length)
{
	write(1, "{ ", 2);
	while (length--)
	{
		if (length == 0)
		{
			ft_putnbr(*analyse);
			write(1, " }\n", 3);
		}
		else
		{
			ft_putnbr(*analyse++);
			write(1, ", ", 2);
		}
	}
}

void		deduce_analyse(int *analyse, int length, int solution[3], int y)
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

void		solve(int fd, int length, int pattern[6], int nb)
{
	char		*tmp;
	int			*analyse;
	int			i;

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
						ft_put_analyse(analyse, length);
		deduce_analyse(analyse, length, pattern + 3, i);
		++i;
	}
	free(tmp);
	free(analyse);
	if (read(fd, tmp, 1) == 1)
		map_error_exit();
	close(fd);
}

void	put_solution(int fd, int solution[6], int length, int nb)
{
	int		i;
	int		j;
	char	*buffer;

	buffer = ft_safe_malloc(length);
	i = 0;
	while (i < solution[4])
	{
		if (read(fd, buffer, length + 1) != length + 1)
			write(1, READ_ERROR, sizeof(READ_ERROR)), exit(0);
		write(1, buffer, length + 1);
		++i;
	}
	j = 0;
	while (j < solution[5])
	{
		if (read(fd, buffer, length + 1) != length + 1)
			write(1, READ_ERROR, sizeof(READ_ERROR)), exit(0);
		ft_memset(buffer + solution[3], solution[2], solution[5]);
		write(1, buffer, length + 1);
		++j;
	}
	i += j;
	while (i < nb)
	{
		if (read(fd, buffer, length + 1) != length + 1)
			write(1, READ_ERROR, sizeof(READ_ERROR)), exit(0);
		write(1, buffer, length + 1);
		++i;
	}
	close(fd);
}

int		main(int ac, char **av)
{
	int		nb;
	int		length;
	int		pattern[6];
	int		skip;

	if (!check_provided_path(ac, av))
		return (1);
	get_intro(av[1], &nb, &skip, pattern);
	get_length(av[1], &length, skip);
	solve(prepare_fd_skip(av[1], skip), length, pattern, nb);
	if (VERBOSE)
		ft_tell_solution(pattern + 3);
	put_solution(prepare_fd_skip(av[1], skip), pattern, length, nb);
	return (0);
}