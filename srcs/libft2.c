#include <stddef.h>

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