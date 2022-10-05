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




int main(int argc, char **argv) {
	t_map map;

	if (argc != 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(1);
	}
	int fd = check_file(argv[1]);

	char *first_line = check_info(fd, &map);
	//todo check map_settings
	check_map(fd, &map, &first_line);
	int i = 0;

	printf("%s\n", map.ea_texture);
	printf("%s\n", map.we_texture);
	printf("%s\n", map.no_texture);
	printf("%s\n", map.so_texture);
	while (map.map[i])
	{
		printf("%s\n", map.map[i]);
		i++;
	}

}
