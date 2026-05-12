/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:24:54 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:24:57 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_allowed_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (IS_BONUS && c == 'D')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

int	is_map_line(char *line)
{
	int	idx;

	if (!line || line[0] == '\0')
		return (0);
	idx = 0;
	while (line[idx])
	{
		if (!is_allowed_map_char(line[idx]))
			return (0);
		idx++;
	}
	return (1);
}

static int	grow_grid(t_map *map)
{
	char	**new_grid;
	int		idx;

	new_grid = ft_calloc(map->height + 2, sizeof(char *));
	if (!new_grid)
		return (printf(ERR_MEMORY), -1);
	idx = 0;
	while (idx < map->height)
	{
		new_grid[idx] = map->grid[idx];
		idx++;
	}
	free(map->grid);
	map->grid = new_grid;
	return (0);
}

int	map_add_line(t_map *map, char *line)
{
	int	len;

	if (!is_map_line(line) || grow_grid(map) < 0)
		return (-1);
	map->grid[map->height] = ft_strdup(line);
	if (!map->grid[map->height])
		return (-1);
	len = ft_strlen(line);
	if (len > map->width)
		map->width = len;
	map->height++;
	return (0);
}
