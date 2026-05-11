/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:23:47 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:23:51 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static char	tile_at(t_map *map, int y, int x)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0)
		return (' ');
	len = ft_strlen(map->grid[y]);
	if (x >= len)
		return (' ');
	return (map->grid[y][x]);
}

static int	cell_is_open(t_map *map, int y, int x)
{
	if (tile_at(map, y - 1, x) == ' ')
		return (-1);
	if (tile_at(map, y + 1, x) == ' ')
		return (-1);
	if (tile_at(map, y, x - 1) == ' ')
		return (-1);
	if (tile_at(map, y, x + 1) == ' ')
		return (-1);
	return (0);
}

static int	validate_cells(t_map *map, int *players)
{
	int		y;
	int		x;
	char	cell;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			cell = map->grid[y][x];
			if (cell != '0' && cell != '1' && cell != ' ' && !is_player(cell))
				return (-1);
			if ((cell == '0' || is_player(cell)) && cell_is_open(map, y, x) < 0)
				return (-1);
			if (is_player(cell))
				(*players)++;
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	players;

	if (!map->grid || map->height == 0)
		return (-1);
	players = 0;
	if (validate_cells(map, &players) < 0)
		return (-1);
	if (players != 1)
		return (-1);
	return (0);
}
