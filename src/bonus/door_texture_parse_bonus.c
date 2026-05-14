/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_texture_parse_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_door_texture_bonus(t_map *map, char *line)
{
	char	*path;

	if (ft_strncmp(line, "DO ", 3) != 0 && ft_strncmp(line, "DO\t", 3) != 0)
		return (0);
	if (!IS_BONUS)
		return (printf(ERR_BONUS_MAP), -1);
	if (map->door_texture.path)
		return (printf(ERR_DUP_TEXTURE), -1);
	path = skip_spaces(&line[2]);
	if (*path == '\0')
		return (printf(ERR_TEXTURE), -1);
	map->door_texture.path = ft_strdup(path);
	if (!map->door_texture.path)
		return (printf(ERR_MALLOC), -1);
	return (1);
}

static int	is_valid_texture_file(char *path)
{
	int	len;
	int	fd;

	if (!path)
		return (-1);
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (printf(ERR_TEXTURE_XPM), -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf(ERR_TEXTURE_PATH), -1);
	close(fd);
	return (0);
}

static int	map_has_doors(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == CHAR_DOOR)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_door_texture_bonus(t_map *map)
{
	if (!IS_BONUS)
		return (0);
	if (!map->door_texture.path)
	{
		if (map_has_doors(map))
			return (printf(ERR_TEXTURE), -1);
		return (0);
	}
	return (is_valid_texture_file(map->door_texture.path));
}
