#define X 25000
#define Y 25000
#define D .5 * 100

#define E '.'
#define O 'o'
#define F 'x'

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

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

int		main(void)
{
	int		i;
	int		j;
	char	buffer[X + 1];
	char	pattern[4];

	ft_putnbr(Y);
	pattern[0] = E;
	pattern[1] = O;
	pattern[2] = F;
	pattern[3] = '\n';
	write(1, pattern, sizeof(pattern));
	srand(clock());
	i = 0;
	while (i < Y)
	{
		j = 0;
		while (j < X)
		{
			if ((rand() % 100) < D)
				buffer[j] = O;
			else
				buffer[j] = E;
			++j;
		}
		buffer[j] = '\n';
		write(1, buffer, sizeof(buffer));
		++i;
	}
}