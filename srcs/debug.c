#include <libft.h>
#include <unistd.h>

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