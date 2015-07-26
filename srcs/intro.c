#include <bsq.h>
#include <libft.h>
#include <config.h>
#include <fcntl.h>

int		get_length(char *str, int *length, int skip)
{
	int 	fd;
	int		ret;
	char	buffer[BUF_SIZE];
	char	*ptr;

	if (!(fd = prepare_fd_skip(str, skip)))
		return (ft_map_error());
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
	return (1);
}

int 	get_intro_2(const char *str, int *nb, int skip, int pattern[6])
{
	char	*buffer;
	int 	fd;

	if (skip <= 3)
		map_error_exit();
	buffer = ft_safe_malloc(skip);
	if ((fd = open(str, O_RDONLY)) <= 0)
		return (ft_map_error());
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
	return (1);
}

int		get_intro(const char *str, int *nb, int *skip, int pattern[6])
{
	int		fd;
	int		ret;
	char	*ptr;
	char	buffer[BUF_SIZE];

	if ((fd = open(str, O_RDONLY)) <= 0)
		return (ft_map_error());
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
	return (get_intro_2(str, nb, *skip, pattern));
}
