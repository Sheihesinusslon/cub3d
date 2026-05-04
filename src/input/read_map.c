#include "../../cub3d.h"

static void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->no_tex = NULL;
	map->so_tex = NULL;
	map->we_tex = NULL;
	map->ea_tex = NULL;
	map->floor_color = NULL;
	map->ceil_color = NULL;
}

static int	has_cub_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 5) != 0)
		return (0);
	return (1);
}

int	read_map(t_map *map, char *filename)
{
	int	fd;

	init_map(map);
	if (!has_cub_extension(filename))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (parse_cub_file(fd, map) < 0)
		return (free_map(map), close(fd), -1);
	close(fd);
	return (0);
}