#include "parser.h"


void get_texture(char **tmp_str, int *counter, t_map *map, char **t_name)
{
	char **splited;
	char *texture;
	char *str;

	if (*counter != 0)
	{
		ft_putstr_fd("Invalid map settings1\n", 2);
		exit(1);
	}
	str = ft_strtrim(*tmp_str, "\n");
	free(*tmp_str);
	*tmp_str = NULL;
	splited = ft_split(str, ' ');
	if (splited[1])
	{
		if(splited[2] && ft_strncmp(splited[2], "\n", ft_strlen(splited[2])))
		{
			ft_putstr_fd("Invalid map settings2\n", 2);
			exit(1);
		}
		if (access(splited[1], F_OK) < 0)
		{
			ft_putstr_fd("Invalid map settings3\n", 2);
			exit(1);
		}
		else
		{
			texture = splited[1];
			*t_name = ft_strdup(texture);
			(*counter)++;
			while (*splited)
			{
				free(*splited);
				splited++;
			}
			free(str);
		}
	}
	else
	{
		ft_putstr_fd("Invalid map settings4\n", 2);
		exit(1);
	}
}

//void get_color(char **str, int *counter, t_map *map, char flag)
//{
//	char **splited;
//	char *res;
//	char **colors;
//	int i = 0;
//	int col;
//
//	if (*counter != 0)
//	{
//		ft_putstr_fd("Invalid map settings\n", 2);
//		exit(1);
//	}
//	splited = ft_split(*str, ' ');
//	if (splited[1])
//	{
//		if(splited[2] && ft_strncmp(splited[2], "\n", ft_strlen(splited[2])))
//		{
//			ft_putstr_fd("Invalid map settings\n", 2);
//			exit(1);
//		}
//		else
//		{
//			res = splited[1];
//			if (res[ft_strlen(res - 1)] == '\n')
//				res[ft_strlen(res - 1)] = '\0';
//			if (flag == 'c')
//				map->celling_color = ft_calloc(4, sizeof(int));
//			else if (flag == 'f')
//				map->floor_color = ft_calloc(4, sizeof(int));
//			colors = ft_split(res, ',');
//			while (colors[i])
//				i++;
//			if (i != 3)
//			{
//				ft_putstr_fd("Invalid map settings\n", 2);
//				exit(1);
//			}
//			i = 0;
//			while (colors[i])
//			{
//				col = ft_atoi(colors[i]);
//				if (col >= 0 && col <= 255)
//					map->celling_color[i] = col;
//				i++;
//			}
//			*counter++;
//			while (*splited)
//			{
//				free(*splited);
//				splited++;
//			}
//			free(*str);
//		}
//	}
//	else
//	{
//		ft_putstr_fd("Invalid map settings\n", 2);
//		exit(1);
//	}
//}

char *check_info(int fd, t_map *map)
{
	char *str;
	int so = 0, no = 0, we= 0, ea = 0, c = 0, f=0;
	char *tmp_str;

	str = get_next_line(fd);
	// todo handle err
	while (str)
	{
		tmp_str = ft_strdup(str);
		while (*tmp_str == ' ')
			tmp_str++;
		if (ft_strnstr(tmp_str, "NO ", 3))
			get_texture(&tmp_str, &no, map, &map->no_texture);
		else if (ft_strnstr(tmp_str, "SO ", 3))
			get_texture(&tmp_str, &so, map, &map->so_texture);
		else if (ft_strnstr(tmp_str, "EA ", 3))
			get_texture(&tmp_str, &ea, map, &map->ea_texture);
		else if (ft_strnstr(tmp_str, "WE ", 3))
			get_texture(&tmp_str, &we, map, &map->we_texture);
		// todo get color
//		else if (ft_strnstr(tmp_str, "C ", 2))
//		{
//
//		}
		// begining of the map
		else if (!ft_strnstr(tmp_str, "\n", 1))
			return str;

		free(str);
		str = NULL;
		// todo handle err
		str = get_next_line(fd);
	}
}