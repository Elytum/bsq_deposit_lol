/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
