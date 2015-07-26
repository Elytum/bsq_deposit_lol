/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t		ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

void		ft_memset(char *str, char c, size_t len)
{
	while (len--)
		*str++ = c;
}

void		ft_putnbr(int nb)
{
	char		buffer[12];
	char		*ptr;

	if (nb == -2147483648)
		write(1, "-2147483648", sizeof("-2147483648"));
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		ptr = buffer + sizeof(buffer) - 1;
		buffer[0] = 0;
		if (nb < 0)
		{
			buffer[0] = 1;
			nb = -nb;
		}
		while (nb > 0)
		{
			*ptr-- = nb % 10 + '0';
			nb /= 10;
		}
		if (buffer[0])
			*ptr-- = '-';
		write(1, ptr + 1, sizeof(buffer) - (long)ptr + (long)buffer - 1);
	}
}

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
