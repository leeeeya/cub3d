#ifndef CUB3D_PARSER_H
#define CUB3D_PARSER_H

# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
#include <sys/fcntl.h>
#include <errno.h>
#include <stdio.h>

typedef struct s_map{
	char **map;
	char *we_texture;
	char *ea_texture;
	char *so_texture;
	char *no_texture;
	int *floor_color;
	int *celling_color;
} t_map;

void check_map(int fd, t_map *map, char **next_line);
char *check_info(int fd, t_map *map);

#endif //CUB3D_PARSER_H
