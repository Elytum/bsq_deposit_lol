#ifndef CONFIG_H
# define CONFIG_H

#define	BUF_SIZE 1024
#define VERBOSE 0
#define MAP_PATH ".tmp/input.bsq"

#define MAP_ERROR "map error\n"
#define MALLOC_ERROR "malloc error\n"
#define READ_ERROR "read error\n"
#define OPEN_ERROR_INTRO "Can't open file \""
#define OPEN_ERROR_END "\", exiting.\n"
#define CREATE_ERROR_BEGIN "Can't create file \""
#define CREATE_ERROR_END "\" which is require to launch the program.\n"
#define PUT_FILE_INTRO "\tSolution of \""
#define PUT_FILE_END "\":\n"

#define MAP_PATH_BEGIN "Opening map \""
#define MAP_PATH_END "\".\n"
#define MAP_INTRO_BEGIN "The size of the first line is "
#define MAP_INTRO_END ".\n"
#define MAP_INTRO_2_BEGIN "There is "
#define MAP_INTRO_2_MIDDLE_SING " line and the pattern is ["
#define MAP_INTRO_2_MIDDLE_MULT " lines and the pattern is ["
#define MAP_INTRO_2_END "].\n"
#define MAP_LENGTH_BEGIN "The size of every line should be \""
#define MAP_LENGTH_END "\".\n"
#define SOLUTION_INTRO "The biggest square have a size of "
#define SOLUTION_MIDDLE " and is starting in ["
#define SOLUTION_END "].\n"

#endif
