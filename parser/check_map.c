#include "parser.h"


t_list	*create_list(int fd, char **next_line)
{
	char	*str;
	t_list	*tmp_map = NULL;
	char	*tmp_str;
	t_list	*new_node;

	tmp_str = *next_line;
	// todo handle err
	while (tmp_str)
	{
		str = ft_strtrim(tmp_str, "\n");
		free(tmp_str);
		tmp_str = NULL;;
		// todo handle err

		int f = 0;
		int l = (int)ft_strlen(str) -1;
		while (str[f] == ' ')
			f++;
		while (str[l] == ' ')
		{
			str[l] = '\0';
			l--;
		}
		if (str[f] != '1' || str[l] != '1')
		{
			ft_putstr_fd("Invalid map1\n", 2);
			exit(1);
		}
		new_node = ft_lstnew(str);
		// todo handle err
		ft_lstadd_back(&tmp_map, new_node);
		tmp_str = get_next_line(fd);
	}

	return (tmp_map);
}

void create_map_array(int fd, t_map *map, char **next_line)
{
	t_list	*map_list;
	int		i;

	i = 0;
	map_list = create_list(fd, next_line);
	int height = ft_lstsize(map_list);
	map->map = (char **)ft_calloc(height + 1, sizeof(char *));
	// todo err handler
	while (map_list)
	{
		map->map[i] = ft_strdup(map_list->content);
		//todo err handler
		ft_lstdelone(map_list, free);
		map_list = map_list->next;
		i++;
	}
	ft_lstclear(&map_list, free);
}

void check_arround(char **map, int i, int j)
{
	if (!i || !j)
	{
		ft_putstr_fd("Invalid map2\n", 2);
		exit(1);
	}
	int a_i = i - 1;
	int a_j = j - 1;
	char ch;
	while(a_i < i +2)
	{
		while (a_j < j + 2)
		{
			ch = map[a_i][a_j];
			if (ch == ' ' || ch == '\0')
			{
				ft_putstr_fd("Invalid map3\n", 2);
				exit(1);
			}
			a_j++;
		}
		a_j = j - 1;
		a_i++;
	}
}

void check_map(int fd, t_map *map, char **next_line)
{
	int count_zero = 0, count_player = 0;
	int i = 0, j = 0;

	create_map_array(fd, map, next_line);
	char ch;

	char *s;
	while(map->map[i])
	{
		s = map->map[i];

		while (map->map[i][j])
		{
			ch = map->map[i][j];
			if (ch == '0' || ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E')
			{
				check_arround(map->map, i, j);
				if (ch == '0')
					count_zero++;
				else
					count_player++;
			}
			else if (ch != '1' && ch != ' ')
			{
				ft_putstr_fd("Invalid map4\n", 2);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (count_zero < 1 || count_player != 1)
	{
		ft_putstr_fd("Invalid map5\n", 2);
		exit(1);
	}

}
