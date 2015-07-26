/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>
#include <config.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			if (ac != 2)
				put_file_path(av[i]);
			solve_map(av[i++]);
		}
	}
	else
	{
		generate_map();
		solve_map(MAP_PATH);
		if ((i = open(MAP_PATH, O_TRUNC)) <= 0)
			create_error(MAP_PATH);
		close(i);
	}
	return (0);
}
