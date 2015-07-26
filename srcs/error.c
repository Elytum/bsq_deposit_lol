/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

int			ft_map_error(void)
{
	write(1, MAP_ERROR, sizeof(MAP_ERROR) - 1);
	return (0);
}

void		create_error(char *str)
{
	write(1, CREATE_ERROR_BEGIN, sizeof(CREATE_ERROR_BEGIN) - 1);
	write(1, str, ft_strlen(str) - 1);
	write(1, CREATE_ERROR_END, sizeof(CREATE_ERROR_END) - 1);
	exit(1);
}

int			solve_error_loop(int fd, char *tmp, int *analyse)
{
	close(fd);
	free(tmp);
	free(analyse);
	return (ft_map_error());
}
