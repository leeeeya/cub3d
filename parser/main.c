#include "parser.h"


int	check_file(char *path)
{
	int		i;
	char	*tmp;
	int		fd;
	int		len;

	i = 0;
	tmp = path;
	len = (int)ft_strlen(tmp);
	if (len <= (int)ft_strlen(".cub"))
	{
		ft_putstr_fd("Invalid file name\n", 2);
		exit(1);
	}
	while (i < len - (int)ft_strlen(".cub"))
	{
		i++;
		tmp++;
	}
	if (ft_strncmp(tmp, ".cub", (int)ft_strlen(".cub")))
	{
		ft_putstr_fd("Invalid file name\n", 2);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0 )
	{
		//todo print err
		exit(errno);
	}
	return (fd);
}

t_list	*create_list(char *path)
{
	int		fd;
	char	*str;
	t_list	*tmp_map = NULL;
	char	*tmp_str;
	t_list	*new_node;

	fd = check_file(path);
	tmp_str = get_next_line(fd);
	// todo handle err
	while (tmp_str)
	{
		str = ft_strtrim(tmp_str, "\n");
		free(tmp_str);
		tmp_str = NULL;;
		// todo handle err
		new_node = ft_lstnew(str);
		// todo handle err
		ft_lstadd_back(&tmp_map, new_node);
		tmp_str = get_next_line(fd);
	}

	return (tmp_map);
}

char **create_map_array(char *path)
{
	t_list	*map_list;
	int		i;
	char **map;

	i = 0;
	map_list = create_list(path);
	int height = ft_lstsize(map_list);
	map = (char **)ft_calloc(height + 1, sizeof(char *));
	// todo err handler
	while (map_list)
	{
		map[i] = ft_strdup(map_list->content);
		//todo err handler
		ft_lstdelone(map_list, free);
		map_list = map_list->next;
		i++;
	}
	ft_lstclear(&map_list, free);
	return map;
}

void check_arround(char **map, int i, int j)
{
	if (!i || !j)
	{
		ft_putstr_fd("Invalid map\n", 2);
		exit(1);
	}
	int a_i = i - 1;
	int a_j = j - 1;
	while(a_i != i +1)
	{
		while (a_j != j + 1)
		{
			char ch = map[a_i][a_j];
			if (ch == ' ' || ch == '\0')
			{
				ft_putstr_fd("Invalid map\n", 2);
				exit(1);
			}
			a_j++;
		}
		a_i++;
	}
}

char **validation_check(char *path)
{
	int count_zero = 0, count_player = 0;
	int i = 0, j = 0;

	char **map = create_map_array(path);
	char ch;

	while(map[i])
	{
		while (map[i][j])
		{
			ch = map[i][j];
			if (ch == '0' || ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E')
			{
				check_arround(map, i, j);
				if (ch == '0')
					count_zero++;
				else
					count_player++;
			}
			else if (ch != '1' && ch != ' ')
			{
				ft_putstr_fd("Invalid map\n", 2);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (count_zero < 1 || count_player != 1)
	{
		ft_putstr_fd("Invalid map\n", 2);
		exit(1);
	}

	return map;
}


int main(int argc, char **argv) {
	if (argc != 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(1);
	}
	char **map = validation_check(argv[1]);
	int i = 0;

	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}

}
