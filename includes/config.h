/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
** The size of buffer (Too low = too slow, too big = unused memory)
*/

# define BUF_SIZE 1024

/*
** Should the program output what's happening ?
*/

# define VERBOSE 0

/*
** Path of the temporary map
*/

# define MAP_PATH ".tmp/input.bsq"

/*
** Errors strings
*/

# define MAP_ERROR "map error\n"
# define MALLOC_ERROR "malloc error\n"
# define READ_ERROR "read error\n"
# define OPEN_ERROR_INTRO "Can't open file \""
# define OPEN_ERROR_END "\", exiting.\n"
# define CREATE_ERROR_BEGIN "Can't create file \""
# define CREATE_ERROR_END "\" which is require to launch the program.\n"

/*
** Verbose strings
*/

# define MAP_PATH_BEGIN "Opening map \""
# define MAP_PATH_END "\".\n"
# define MAP_INTRO_BEGIN "The size of the first line is "
# define MAP_INTRO_END ".\n"
# define MAP_INTRO_2_BEGIN "There is "
# define MAP_INTRO_2_MIDDLE_SING " line and the pattern is ["
# define MAP_INTRO_2_MIDDLE_MULT " lines and the pattern is ["
# define MAP_INTRO_2_END "].\n"
# define MAP_LENGTH_BEGIN "The size of every line should be \""
# define MAP_LENGTH_END "\".\n"
# define SOLUTION_INTRO "The biggest square have a size of "
# define SOLUTION_MIDDLE " and is starting in ["
# define SOLUTION_END "].\n"
# define PUT_FILE_INTRO "\tSolution of \""
# define PUT_FILE_END "\":\n"

#endif
