#ifndef LIBFT_H
# define LIBFT_H

#include <sys/types.h>

int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, char c);
char	*ft_strnchr(const char *str, char c, int n);
size_t	ft_strlen(const char *str);
void	ft_memset(char *str, char c, size_t len);
void	ft_putnbr(int nb);

#endif
