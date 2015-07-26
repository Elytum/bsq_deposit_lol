#include <bsq.h>
#include <config.h>
#include <libft.h>
#include <unistd.h>

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
