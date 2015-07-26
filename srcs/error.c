#include <config.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

int			ft_map_error(void)
{
	write(1, MAP_ERROR, sizeof(MAP_ERROR) - 1);
	return (0);
}

void		map_error_exit(void)
{
	write(1, MAP_ERROR, sizeof(MAP_ERROR) - 1);
	exit(0);
}

void		ft_open_error(const char *str)
{
	write(1, OPEN_ERROR_INTRO, sizeof(OPEN_ERROR_INTRO));
	write(1, str, ft_strlen(str));
	write(1, OPEN_ERROR_END, sizeof(OPEN_ERROR_END));
	exit(1);
}

void	create_error(char *str)
{
	write(1, CREATE_ERROR_BEGIN, sizeof(CREATE_ERROR_BEGIN) - 1);
	write(1, str, ft_strlen(str) - 1);
	write(1, CREATE_ERROR_END, sizeof(CREATE_ERROR_END) - 1);
	exit(1);
}
