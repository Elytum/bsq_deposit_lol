/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <config.h>
#include <unistd.h>

void		ft_tell_path(const char *str)
{
	write(1, MAP_PATH_BEGIN, sizeof(MAP_PATH_BEGIN) - 1);
	write(1, str, ft_strlen(str));
	write(1, MAP_PATH_END, sizeof(MAP_PATH_END) - 1);
}

void		ft_tell_intro(int nb)
{
	write(1, MAP_INTRO_BEGIN, sizeof(MAP_INTRO_BEGIN) - 1);
	ft_putnbr(nb);
	write(1, MAP_INTRO_END, sizeof(MAP_INTRO_END) - 1);
}

void		ft_tell_intro_2(int nb, int pattern[6])
{
	char		buffer[11];

	write(1, MAP_INTRO_2_BEGIN, sizeof(MAP_INTRO_2_BEGIN) - 1);
	ft_putnbr(nb);
	if (nb > 1)
		write(1, MAP_INTRO_2_MIDDLE_MULT, sizeof(MAP_INTRO_2_MIDDLE_MULT) - 1);
	else
		write(1, MAP_INTRO_2_MIDDLE_SING, sizeof(MAP_INTRO_2_MIDDLE_SING) - 1);
	buffer[0] = '\'';
	buffer[1] = pattern[0];
	buffer[2] = '\'';
	buffer[3] = ',';
	buffer[4] = '\'';
	buffer[5] = pattern[1];
	buffer[6] = '\'';
	buffer[7] = ',';
	buffer[8] = '\'';
	buffer[9] = pattern[2];
	buffer[10] = '\'';
	write(1, buffer, sizeof(buffer));
	write(1, MAP_INTRO_2_END, sizeof(MAP_INTRO_2_END) - 1);
}

void		ft_tell_length(int nb)
{
	write(1, MAP_LENGTH_BEGIN, sizeof(MAP_LENGTH_BEGIN) - 1);
	ft_putnbr(nb);
	write(1, MAP_LENGTH_END, sizeof(MAP_LENGTH_END) - 1);
}

void		ft_tell_solution(int solution[3])
{
	write(1, SOLUTION_INTRO, sizeof(SOLUTION_INTRO));
	ft_putnbr(solution[2]);
	write(1, SOLUTION_MIDDLE, sizeof(SOLUTION_MIDDLE));
	ft_putnbr(solution[0]);
	write(1, ", ", sizeof(", "));
	ft_putnbr(solution[1]);
	write(1, SOLUTION_END, sizeof(SOLUTION_END));
}
