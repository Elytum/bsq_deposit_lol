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

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>

int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, char c);
char	*ft_strnchr(const char *str, char c, int n);
size_t	ft_strlen(const char *str);
void	ft_memset(char *str, char c, size_t len);
void	ft_putnbr(int nb);

#endif
